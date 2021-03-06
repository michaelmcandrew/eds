<?php
/*
 +--------------------------------------------------------------------+
 | CiviCRM version 4.0                                                |
 +--------------------------------------------------------------------+
 | This file is a part of CiviCRM.                                    |
 |                                                                    |
 | CiviCRM is free software; you can copy, modify, and distribute it  |
 | under the terms of the GNU Affero General Public License           |
 | Version 3, 19 November 2007 and the CiviCRM Licensing Exception.   |
 |                                                                    |
 | CiviCRM is distributed in the hope that it will be useful, but     |
 | WITHOUT ANY WARRANTY; without even the implied warranty of         |
 | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.               |
 | See the GNU Affero General Public License for more details.        |
 |                                                                    |
 | You should have received a copy of the GNU Affero General Public   |
 | License and the CiviCRM Licensing Exception along                  |
 | with this program; if not, contact CiviCRM LLC                     |
 | at info[AT]civicrm[DOT]org. If you have questions about the        |
 | GNU Affero General Public License or the licensing of CiviCRM,     |
 | see the CiviCRM license FAQ at http://civicrm.org/licensing        |
 +--------------------------------------------------------------------+
*/

/**
 * Field handler to provide acess control for the state field (which is a lookup)
 *
 * @ingroup civicrm_field_handlers
 */
class civicrm_handler_field_state extends views_handler_field {
    static $_states;
    static $_states_full;
    
    function construct( ) {
        if ( ! self::$_states || ! self::$_states_full) {
            if ( ! civicrm_initialize( ) ) {
                return;
            }
            require_once 'CRM/Core/PseudoConstant.php';
            self::$_states = CRM_Core_PseudoConstant::stateProvinceAbbreviation( );
            self::$_states_full = CRM_Core_PseudoConstant::stateProvince( );
        }
    }

    function render( $values ) {
        $sid = $values->{$this->field_alias};
        if ( empty( $sid ) ||
             (int ) $sid <= 0 ) {
            return null;
        }
        
        if ( $this->options['prov_display'] == 1 ) {
            return self::$_states[$values->{$this->field_alias}];
        } else {
            return self::$_states_full[$values->{$this->field_alias}];
        }
    }
    
    function option_definition() {
        $options = parent::option_definition();
        $options['prov_display'] = array('default' => '');
        return $options;
    }
    
    function options_form(&$form, &$form_state) {
        parent::options_form($form, $form_state);
        $form['prov_display'] = array(
                                      '#type' => 'radios',
                                      '#title' => 'Phone type for this field',
                                      '#options' => array(1 => 'Display state/province abbreviations', 2 => 'Display full state/province name'),
                                      '#description' => t('Display full or abbreviated province name'),
                                      '#default_value' => $this->options['prov_display']
                                      );
    }
}
