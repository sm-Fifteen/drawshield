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

// digit

$charge = array (

  'patterns' => array (
  'numerals?',
  'numbers?',
  'digits?',
  ),

  'file' => 'inkscape/digit-0.svg', // overridden in use

  'flags' => array (
    'get_item' => 1,
    'default_colour' => 'sable',
  ),
);

if ( $node != null ) {

  
    $numbers = array ( 'one' => '1', 'two' => '2', 'three' => '3', 'four' => '4', 'five' => '5',
        'six' => '6', 'seven' => '7', 'eight' => '8', 'nine' => '9', 'zero' => '0' );
  
    $digit = get_mod ( $node, 'item' );
    $try = $digit{0};
    if ( is_numeric($try ) ) 
      $digit = $try;
    elseif ( array_key_exists(strtolower($digit), $numbers) )
      $digit = $numbers[strtolower($item)];
    $charge['file'] = "inkscape/digit-$digit.svg";
}
