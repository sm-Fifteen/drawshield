<?php /* Copyright 2010 Karl R Wilcox

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License */

// letter

$charge = array (

  'patterns' => array (
  'letters?',
  ),

  'file' => 'inkscape/letter-a.svg', // overridden in use
  
  'flags' => array (
    'get_item' => 1,
    'default_colour' => 'sable',
  ),

);

if ( $node != null ) {

$item = get_mod( $node, 'item' );
$charge['file'] = 'inkscape/letter-' . (strtolower($item{0})) . '.svg';


}


