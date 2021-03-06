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


$ordinary = array(
  'link' => 'http://karlwilcox.com/parker/c/canton',
      'patterns' => array (
        'cantons?',
      ),
  'modifiers' => array (
    array ( null, 'of pretence', 'ignore',    ),
    array ('subshield', 'of !pretence', 'shieldmod', ),
  ),
      
      'doc' => 'Stuff...',
      
      'shape_spec' => 'X-8Y-8a208C208E208g208', 
			'if_ord_on' => 'scale',
			'feature_size' => 30,
);

if ( $node != null ) {
  foreach ( $node->parentNode->childNodes as $sibling ) {
    if ( $sibling->nodeName == 'ordinary' and $sibling->getAttribute('subtype') == 'chief' ) {
      $ordinary['shape_spec'] = 'X-8Y-8a308C308E308g308';
      $ordinary['feature_size'] = 40;
      break;
    }
  }
}

?>
