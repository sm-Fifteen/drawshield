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

$ordinary = array (
  'patterns' => array (
    'chevron(el)?s? couched',
  ), 
  
  'either' => true,
  
  'doc' => '',
  'shape_spec' => array ( "NC" =>  'X0Y-100B700D700f200H500F500h200', "CH" =>  'X0Y200B700D700f200H500F500h200' ),
  'bounding_box' => array ( "NC" => '500,1000,0,0', 'CH' => '500,1000,0,200' ),
);

?>
