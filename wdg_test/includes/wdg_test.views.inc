<?php

function wdg_test_views_data(){
	$data = array();
	
	$data['wdg_test']['table']['group'] = t('Customfield');
	
	$data['wdg_test']['table']['join']['node'] = array(
		'left_field' => 'nid',
		'field' => 'pid',
	
		);
	$data['wdg_test']['pid'] = array(
	  'title' => t('Pid'),
	  'help' => t('Custom field Pid.'), // The help that appears on the UI,
	  // Information for displaying the nid
	  'field' => array(
		'handler' => 'views_handler_field_node',
		'click sortable' => TRUE,
	  ),
	  // Information for accepting a nid as an argument
	  'argument' => array(
		'handler' => 'views_handler_argument_node_nid',
		'name field' => 'title', // the field to display in the summary.
		'numeric' => TRUE,
		//'validate type' => 'pid', /// MIGHT BE WRONG
	  ),
	  // Information for accepting a nid as a filter.
	  'filter' => array(
		'handler' => 'views_handler_filter_numeric',
	  ),
	  // Information for sorting on a nid.
	  'sort' => array(
		'handler' => 'views_handler_sort',
	  ),
	  
	  	'relationship' => array(
	  'label' => t('Node'),
      'base' => 'node',
      'base field' => 'nid',

	),
	);
	

	$data['wdg_test']['value'] = array(
	  'title' => t('Field Value'),
	  'help' => t('Custom field Value.'), // The help that appears on the UI,
	  // Information for displaying the nid
	  'field' => array(
		'handler' => 'views_handler_field_node',
		'click sortable' => TRUE,
	  ),
	  // Information for accepting a nid as an argument
	  'argument' => array(
		'handler' => 'views_handler_argument_node_nid',
		'name field' => 'title', // the field to display in the summary.
		'numeric' => TRUE,
		//'validate type' => 'pid', /// MIGHT BE WRONG
	  ),
	  // Information for accepting a nid as a filter.
	  'filter' => array(
		'handler' => 'views_handler_filter_numeric',
	  ),
	  // Information for sorting on a nid.
	  'sort' => array(
		'handler' => 'views_handler_sort',
	  ),
	  /*'relationship' => array(
	  'label' => t('Node'),
      'base' => '',
      'base field' => 'nid',

	),*/
	);
	
	
	return $data;


}