/**
 * @file
 * scripts for show/hide selectbox
 * @param {type} $
 * @param {type} Drupal
 * @param {type} window
 * @param {type} document
 * @param {type} undefined
 * @returns {undefined}
 */
(function ($, Drupal, window, document, undefined) {
    $(document).ready(function () {
        var currentDay = new Date();
        var day = currentDay.getDay();
        var hours = currentDay.getHours();
        var day = currentDay.getDay();
        
        var min = 0;
        
        if (hours >= 15) {
          min = '+1D';           
        }
        
        //if (hours >= 13) {
            $('#edit-delivery').find(".form-item-delivery-delivery-pane-field-display-date input").datepicker({
                minDate: min, //'+1D',
                dateFormat: 'dd M y',
                changeMonth: false,
                changeYear: false,
                
                beforeShowDay: function (date) {
                    var currentDay = new Date();
                    var day = currentDay.getDay();
                    var hours = currentDay.getHours();
                    var day = date.getDay();
                    return [day !== 0 && day !== 6, ""];
                }
                
            });
        //}

        var value = $('#edit-delivery-delivery-date option');

        $('select#edit-delivery-delivery-date').removeAttr('disabled');

        //add default date
        var val = $('#edit-delivery-delivery-pane-field-display').find("input").datepicker("getDate");        
        if (!val) {
          $('#edit-delivery-delivery-pane-field-display').find("input").datepicker("setDate", new Date());
        }
        
        //END add default value
    });

})(jQuery, Drupal, this, this.document);

