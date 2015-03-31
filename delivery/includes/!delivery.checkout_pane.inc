<?php

/**
 * 
 * @return type
 */
function delivery_ajax_disable_select() {
    ctools_include('ajax');
    $commands = array();
    $commands[] = ajax_command_invoke('select[name="delivery[delivery_date]"]', 'removeAttr', array("disabled"));
    

    return array('#type' => 'ajax', '#commands' => $commands);
}

/**
 * Custom checkout pane.
 * 
 * Function name should consist of <pane key>_checkout_form.
 * @global type $user
 * @param type $form
 * @param type $form_state
 * @param type $checkout_pane
 * @param type $order
 * @return boolean|string
 */
function delivery_pane_checkout_form($form, $form_state, $checkout_pane, $order) {
    global $user;
    $manual = variable_get('delivery_manual');

    $order_wrapper = entity_metadata_wrapper('commerce_order', $order);
    $shipping = $order_wrapper->commerce_customer_shipping->commerce_customer_address->value();
    $country = $shipping['country'];
    $shortcode = $shipping['postal_code'];
    $order_id = commerce_cart_order_id($uid = $user->uid);
    $weekends = variable_get('delivery_manual');

    $london_codes = zip_codes();

    if ($country != 'GB') {
        return FALSE;
    }

    if (!empty($shortcode) && is_string($shortcode)) {
       // foreach ($london_codes as $c) {
           // if (0 === stripos($shortcode, $c)) {
           if (in_array(strtoupper($shortcode), $london_codes)) {
                $options = array(
                    '00.00' => '---/---',
                    'Daytime (9-6pm)' => 'Daytime (9-6pm)',
                    'Lunchtime (11am - 1pm)' => 'Lunchtime (11am - 1pm)',
                    'Early afternoon (1pm - 3pm)' => 'Early afternoon (1pm - 3pm)',
                    'Late afternoon (3pm - 5pm)' => 'Late afternoon (3pm - 5pm)',
                );

                $checkout_form['delivery_pane_field_display']['#prefix'] = '<div id="delivery-wrapper">';
                $checkout_form['delivery_pane_field_display']['#suffix'] = '</div>';

                $checkout_form['delivery_pane_field_display'] = array(
                    '#type' => 'date_popup',
                    '#default_value' => variable_get('choosed', NULL),
                    '#size' => 21,
                    //'#maxlength' => 100,
                    '#date_flexible' => 0,
                    '#date_timezone' => date_default_timezone(),
                    '#date_year_range' => (date('Y')) . ':+0',
                    '#date_format' => 'd M y',
                    '#required' => TRUE,
                    //Add inline js
                    '#datepicker_options' => array(
                        'minDate' => 0,
                        'changeMonth' => FALSE,
                        'changeYear' => FALSE,
                        'firstDay' => 1,
                    ),
                    '#ajax' => array(
                        'callback' => 'delivery_form_refresh',
                        'wrapper' => 'test-form-wrapper',
                    ),
                );
                $checkout_form['#attached']['js'] = array(
                    drupal_get_path('module', 'delivery') . '/js/delivery.js' => array(),
                    array(
                        // Pass PHP variables to Drupal.settings.
                        'data' => array('delivery' => $manual),
                        'type' => 'setting',
                    ),
                );
                $checkout_form['delivery_pane_field_display']['#attached']['js'] = array(
                    drupal_get_path('module', 'delivery') . '/js/london_date.js',
                );

                $hours = (int)date('Hi');
                
                $date_now = variable_get('date_now');
                if ($date_now == TRUE && $hours <= 1700) {
                    if ($hours <= 859 && $hours <= 1659) {
                        $options = array(
                            '00.00' => '---/---',
                            'Daytime (9-6pm)' => 'Daytime (9-6pm)',
                            'Lunchtime (11am - 1pm)' => 'Lunchtime (11am - 1pm)',
                            'Early afternoon (1pm - 3pm)' => 'Early afternoon (1pm - 3pm)',
                            'Late afternoon (3pm - 5pm)' => 'Late afternoon (3pm - 5pm)',
                        );
                    }
                    if ($hours >= 859 && $hours <= 1059) {
                        $options = array(
                            '00.00' => '---/---',
                            'Daytime (9-6pm)' => 'Daytime (9-6pm)',
                            'Early afternoon (1pm - 3pm)' => 'Early afternoon (1pm - 3pm)',
                            'Late afternoon (3pm - 5pm)' => 'Late afternoon (3pm - 5pm)',
                        );
                    } elseif ($hours >= 1059 && $hours <= 1259) {
                        $options = array(
                            '00.00' => '---/---',
                            'Daytime (9-6pm)' => 'Daytime (9-6pm)',
                            'Late afternoon (3pm - 5pm)' => 'Late afternoon (3pm - 5pm)',
                        );
                    } elseif ($hours >= 1259 && $hours <= 1659) {
                        $options = array(
                            '00.00' => '---/---',
                            'Daytime (9-6pm)' => 'Daytime (9-6pm)',
                        );
                    }

                    $checkout_form['delivery_date'] = array(
                        '#type' => 'select',
                        '#title' => t('Time'),
                        '#options' => $options,
                        '#disabled' => FALSE,
                    );
                }
                $choosed_date = variable_get('choosed');
                $current_date = date('Y-m-d');
                
                if ($choosed_date === $current_date && $hours >= 1259) {
                  
                $checkout_form['delivery_date'] = array(
                        '#type' => 'select',
                        '#title' => t('Time'),
                        '#options' => $options,
                        '#disabled' => FALSE,
                        '#attributes' => array(
                          'class' => array(
                              'disabled'
                              ),  
                        ),
                    );
                } elseif ($choosed_date !== $current_date ) {
                    $checkout_form['delivery_date'] = array(
                        '#type' => 'select',
                        '#title' => t('Time'),
                        '#options' => $options,
                        '#disabled' => FALSE,
                    );
                }
                return $checkout_form;
            }
        //}
        //if (0 !== stripos($shortcode, $c)) {
        else {

            $checkout_form['delivery_pane_field_display']['#prefix'] = '<div id="delivery-wrapper">';
            $checkout_form['delivery_pane_field_display']['#suffix'] = '</div>';

            $checkout_form['delivery_pane_field_display_1'] = array(
                '#type' => 'date_popup',
                //'#default_value' => variable_get('choosed', NULL),
                '#size' => 21,
                //'#maxlength' => 100,
                '#date_flexible' => 0,
                '#date_timezone' => date_default_timezone(),
                '#date_year_range' => (date('Y')) . ':+0',
                '#date_format' => 'd M y',
                '#required' => TRUE,
                '#datepicker_options' => array(
                    'minDate' => 1,
                    'changeMonth' => FALSE,
                    'changeYear' => FALSE,
                    'firstDay' => 1,
                ),
                '#prefix' => '<div id="datepicker-schedule">',
                '#suffix' => '</div>',
            );
            $checkout_form['#attached']['js'] = array(
                drupal_get_path('module', 'delivery') . '/js/delivery.js' => array(),
                array(
                    // Pass PHP variables to Drupal.settings.
                    'data' => array('delivery' => $manual),
                    'type' => 'setting',
                ),
            );
            $checkout_form['delivery_pane_field_display_1']['#attached']['js'] = array(
                drupal_get_path('module', 'delivery') . '/js/date.js',
            );

            return $checkout_form;
        }
    }

    delivery_ajax_disable_select();
    return false;
}

/**
 * Ajax callback
 * @param type $form
 * @param type $form_state
 * @return type
 */
function delivery_form_refresh($form, $form_state) {
    ctools_include('ajax');
    variable_del('choosed');
    $choosed_date = $form_state['values']['delivery']['delivery_pane_field_display'];
    $current_date = date('Y-m-d');

    variable_del('date_now');
    variable_set('choosed', $choosed_date);
    if ($choosed_date == $current_date) {
        variable_set('date_now', TRUE);
    } else {
        variable_set('date_now', FALSE);
    }

    $commands = array();
    $commands[] = ctools_ajax_command_reload();
    $commands[] = ajax_command_invoke('select[name="delivery[delivery_date]"]', 'attr', array("disabled", "disabled"));
  
    return array('#type' => 'ajax', '#commands' => $commands);
}

/**
 * Checkout pane callback: returns the cart contents review data for the
 *   Review checkout pane.
 * @param type $form
 * @param type $form_state
 * @param type $checkout_pane
 * @param type $order
 * @return type
 */
function delivery_pane_review($form, $form_state, $checkout_pane, $order) {
    $content = array();
    $data = $order->data['delivery_pane_field_display'];

    $content[] = array(
        '#type' => 'item',
        '#title' => t('Date'),
        '#markup' => date('d M y, l', strtotime($data)),
    );
    if (isset($order->data['delivery_pane_field_time_slot']) && $order->data['delivery_pane_field_time_slot'] != NULL) {
        $content[] = array(
            '#type' => 'item',
            '#title' => t('Time slot'),
            '#markup' => $order->data['delivery_pane_field_time_slot'],
        );
    }
    return drupal_render($content);
}

/**
 * 
 * @param type $form
 * @param type $form_state
 * @return boolean
 */
function delivery_pane_checkout_form_validate($form, $form_state) {
    //do something for validation
    return TRUE;
}