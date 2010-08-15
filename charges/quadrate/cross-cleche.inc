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

// cross-cleche

$charge = array (

  'patterns' => array (
  'cross(let|lets|es)? (cleche|urde)',
  ),
  'either' => array ( 'quadrate', ),

  'doc' => 'Stuff...',

  'body' => '<path d="m 190,0 20,0 60,60 -20,20 0,120 -100,0 0,-120 -20,-20 z m 210,190 0,20 -60,60 -20,-20 -120,0 0,-100 120,0 20,-20 z m -400,20 0,-20 60,-60 20,20 120,0 0,100 -120,0 -20,20 z m 210,190 -20,0 -60,-60 20,-20 0,-120 100,0 0,120 20,20 z" />',
  'width' => 400,
  'height' => 400,

)

?>