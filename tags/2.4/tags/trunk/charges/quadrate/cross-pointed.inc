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

// cross-pointed

$charge = array (

  'patterns' => array (
  'cross(let|lets|es)? pointed',
  'cross(let|lets|es)? (ve|u)rd(y|e|ee)',
  'cross(let|lets|es)? champaine',
  ),
  'either' => array ( 'quadrate', ),

  'doc' => 'Stuff...',

);

$main = 'l10,10v80';

include ('charges/quadrate/_quadrate8.inc');
  
?>
