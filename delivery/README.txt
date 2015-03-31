delivery.info
Information about module, description, paths to included files, version etc.
/***/
delivery.module
 - all settigs are located here. 
delivery_commerce_checkout_pane_info() - settings for desired delivery date pane

We can also output some settings into admin panel (Implements base_settings_form()), but there is no such need in this case. 

delivery_entity_view() - function responsible for tab display on the page

delivery_ctools_plugin_directory() - here we indicate where the plugin is located responsible for countries display (same as in Drupal commerce I am using Ctools functional)

/******/
delivery.checkout_pane.inc - all callbacks are here

delivery_page_checkout_form() - create new step after checkout (new step2)

delivery_pane_checkout_form() - create a form (it is a dropdown with dates)

delivery_pane_checkout_form_submit() - here we record the selected value and submit the form

delivery_pane_review() -  this function allows to show our selected value on checkout/%/review step

delivery_standard_widget_refresh() - this is a callback (it is called from addess.inc)

/*****/
delivery.css - styles we can use

delivery.js - If need - we can add js code here

