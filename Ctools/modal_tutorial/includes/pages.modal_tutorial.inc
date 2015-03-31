<?php

  function modal_tutorial_page_callback(){
    ctools_include('ajax');
	ctools_include('modal');

	ctools_modal_add_js();
	$build['paragraph'] = array(
		'#prefix' => '<p>',
		'#suffix' => '</p>',
		'#markup' => t('Click to see modal'),
	);
	
	$text = t('Show a popup!');
	$dest = 'ajax/nojs/show/modal';
	$alt = t('Show a popup by clicking!');
	$link = ctools_modal_text_button($text, $dest, $alt);
	
	$build['popup_link'] = array(
		'#markup' => $link,
	
	
	);
	return render($build);
  }
  
  /**
  *Page callback 
  *Generates the modal contents 
  */ 
  
  function ajax_modal_tutorial_modal_callback($js = NULL){
	if($js){
		ctools_include('ajax');
		ctools_include('modal');
		
		$title = t('My cool popup');
		
		$build = array(
			'#prefix' => '<strong>',
			'#suffix' => '</strong>',
			'#markup' => t('Hello world cool popup'),
		);
		$output = render($build);
		ctools_modal_render($title, $output);
	
	}
  }