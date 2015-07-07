<?php
/**
 * Page callback for hello-world.
 */
function drupal_training_hello_world() {
  return 'Hello World';
}

/**
 * Callback function for hello­form.
 */
function drupal_training_hello_form($form, &$form_state, $node) {
  $form['#node'] = $node;

  $form['new_title'] = array(
    '#type' => 'textfield',     '#title' => t('New title'),
    '#default_value' => $node­->title,
    '#required' => TRUE,
  );

  $form['accept'] = array(
    '#type' => 'checkbox',
    '#title' => t('I accept the terms and conditions'),
    '#required' => TRUE,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Change title'),
  );

  return $form;
}

/**
 * Validate callback for drupal_training_hello_form.
 */
function drupal_training_hello_form_validate($form, &$form_state) {
  if (strlen($form_state['values']['new_title']) < 3) {
    form_set_error(
      'new_title',
       t('The new title must have at least 3 characters')
    );
  }
}

/**
 * Submit callback for drupal_training_hello_form.
 */
/*
function drupal_training_hello_form_submit($form, &$form_state) {
  $form['#node']­->title = $form_state['values']['new_title'];
  node_save($form['#node']);
  $form_state['redirect'] = 'node/' . $form['#node']­->nid;
}
//*/
