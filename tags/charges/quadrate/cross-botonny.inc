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

// cross-botonny

$charge = array (

  'patterns' => array (
  'cross(es)? (botonny|trefle)',
  ),
  'either' => array ( 'quadrate', ),

  'doc' => 'Stuff...',

  'height' => 400,
  'width' => 400,
  
  'body' => '<polygon points="175,20 175,175 20,175 20,225 175,225 175,380 225,380 225,225 380,225 380,175 225,175 225,20" />
      <circle cx="200" cy="35" r="35"/><circle cx="170" cy="80" r="35"/><circle cx="230" cy="80" r="35"/>
      <circle cx="35" cy="200" r="35"/><circle cx="80" cy="170" r="35"/><circle cx="80" cy="230" r="35"/>
      <circle cx="365" cy="200" r="35"/><circle cx="320" cy="170" r="35"/><circle cx="320" cy="230" r="35"/>
      <circle cx="200" cy="365" r="35"/><circle cx="170" cy="320" r="35"/><circle cx="230" cy="320" r="35"/>',

  'fitchy' => '<polygon points="175,20 175,175 20,175 20,225 175,225 225,225 380,225 380,175 225,175 225,20" />
      <circle cx="200" cy="35" r="35"/><circle cx="170" cy="80" r="35"/><circle cx="230" cy="80" r="35"/>
      <circle cx="35" cy="200" r="35"/><circle cx="80" cy="170" r="35"/><circle cx="80" cy="230" r="35"/>
      <circle cx="365" cy="200" r="35"/><circle cx="320" cy="170" r="35"/><circle cx="320" cy="230" r="35"/>
      <path d="M175,200L175,425 200,500 225,425 225,200Z" />',
);

include ('charges/quadrate/_quadrate.inc');

?>
