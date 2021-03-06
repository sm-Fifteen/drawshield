<?php /* Copyright 2010 Karl R. Wilcox

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License. */

// TODO groups inside transformed groups probably won't work...   
   
$groupXTrans = 0;
$groupYTrans = 0;
$inkGroups = null;

function add_item($item, $curID) {
  global $inkGroups;
  global $groupXTrans, $groupYTrans;
  
  switch ($item->getName()) {
    case 'path':
      $inkGroups[$curID] .= get_path($item);
      break;
    case 'rect':
      $inkGroups[$curID] .=  get_rect($item);
      break;
    case 'g':
      $prevID = $curID;
      $gID = $item['id'];
      $name = sprintf("%s",$item['id']);
  	  list($groupXTrans, $groupYTrans) = get_transform($item['transform']);
      if ( (strncasecmp($name,'layer',5) !== 0) and (preg_match('/g[0-9]+/', $name) != 1) ) { // just ignore layers or auto named groups
        $curID = $name;
        $inkGroups[$name] = '';
      }
      foreach( $item->children() as $child ) 
        add_item($child, $curID);
      $groupXTrans = 0;
      $groupYTrans = 0; // Make this recursive?
      $curID = $prevID;
      break;
    default:
      // draw_message('INTERNAL', 'inkscape: element not handled - ' . $item->getName());
      break;
  }
}

function split_style ( $styles ) {
  $retval = '';
  $styles = explode(';', $styles);
  foreach ($styles as $style) {
    list($setting,$value) = explode(':',$style);
    switch($setting) {
      case 'fill': // Any of the "primary" colours are just placeholders, to be replaced by the charge colour
        if ( !in_array( $value, array ( '#ff0000', '#00ff00', '#0000ff', '#ffff00')) ) $retval .= 'fill="' . $value . '" ';
        break; // any other colour is left as it is
      case 'fill-opacity':
      case 'opacity':
        if ( $value != '1' ) $retval .= $setting . '="' . $value . '" ';
        break;
      case 'stroke-width':
      case 'fill-rule':
        $retval .= $setting . '="' . $value . '" ';
        break;
      case 'stroke':
        if ( $value == '#000000' ) $value = 'inherit';
        $retval .= 'stroke="' . $value . '" ';
        break;
    }
  }
  return $retval;
}

function get_rect($rect) {
  $retval = '<rect ';
  $retval .= split_style($rect['style']);
  $retval .= 'width="' . $rect['width'] . '" ';
  $retval .= 'height="' . $rect['height'] . '" ';
  $retval .= 'x="' . $rect['x'] . '" ';
  $retval .= 'y="' . $rect['y'] . '" ';
  $retval .= " />\n";
  return $retval;
}

function get_transform ( $transform ) {
  global $groupXTrans, $groupYTrans;
  
  if ( !$transform ) 
    return array($groupXTrans, $groupYTrans);
  preg_match('/translate *\(([\d\.-]+),([\d\.-]+)\)/', $transform, $match );
  return array ( ($match[1] + $groupXTrans), ($match[2] + $groupYTrans) );
}

function applyTransform( $path, $transform ) {
  global $groupXTrans, $groupYTrans;
  if ( !$transform ) return $path;
  /* Inkscape only seems to use translate on its own or matrix transforms - for the moment only handle these */
  if ( preg_match('/translate *\(([\d\.-]+),([\d\.-]+)\)/', $transform, $match ) == 1 )
    return translatePath($path, ($match[1] + $groupXTrans), ($match[2] + $groupYTrans));
  elseif ( preg_match('/matrix *\(([\d\.-]+),([\d\.-]+),([\d\.-]+),([\d\.-]+),([\d\.-]+),([\d\.-]+)\)/', $transform, $match ) == 1 )
    return matrixPath($path, $match[1], $match[2], $match[3], $match[4], $match[5], $match[6]);
  else
    draw_message('warning','transform problem ' . $transform );
  return $path;
}

function get_path($path) {
  $retval = '<path ';
  $retval .= split_style( $path['style']);
  $retval .= 'd="' . (applyTransform($path['d'], $path['transform'])) . "\" />\n";
  return $retval;
}

function ink2chg($filename) {
  global$inkGroups;
  
  $retval = array();
  $inkGroups = array('body' => '');
  
  if ( ($svg = simplexml_load_file($filename)) == null ) {
    draw_message('internal',"XML error reading $filename");
    return null;
  }
  $retval['height'] = floatval($svg['height']);
  $retval['width'] = floatval($svg['width']);
  $metadata = $svg->xpath('//cc:Agent/dc:title');
  if ( is_array($metadata) and count($metadata) > 0) {
    $retval['licence'] = $metadata[0];
  }
  
  foreach( $svg->children() as $child ) 
    add_item($child,'body');
  
  $features = array();
  $body = '';
  foreach ( $inkGroups as $key => $data ) {
    if ( $key == 'body' )
      $retval['body'] = $data;
    else
      $features[$key] = array('body' => $data);
  }   
  if ( count($features) )
    $retval['features'] = $features;
  return $retval;
}
  
 
?>
