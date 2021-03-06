<?php 

function uf_join_create_example(){
    $params = array(
    
                  'module' 		=> 'CiviContribute',
                  'entity_table' 		=> 'civicrm_contribution_page',
                  'entity_id' 		=> '1',
                  'weight' 		=> '1',
                  'uf_group_id' 		=> '11',
                  'is_active' 		=> '1',
                  'version' 		=> '3',
                  'sequential' 		=> '1',

  );
  require_once 'api/api.php';
  $result = civicrm_api( 'uf_join','create',$params );

  return $result;
}

/*
 * Function returns array of result expected from previous function
 */
function uf_join_create_expectedresult(){

  $expectedResult = 
     array(
           'is_error' 		=> '0',
           'version' 		=> '3',
           'count' 		=> '1',
           'id' 		=> '0',
           'values' 		=> array(           '0' =>  array(
                      'id' => '10',
                      'is_active' => '1',
                      'module' => 'CiviContribute',
                      'entity_table' => 'civicrm_contribution_page',
                      'entity_id' => '1',
                      'weight' => '1',
                      'uf_group_id' => '11',
           ),           ),
      );

  return $expectedResult  ;
}

