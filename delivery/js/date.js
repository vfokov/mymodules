/**
 * This number relates to which day of the week you want to disable.
 Sunday = 0
 Monday = 1
 Tuesday = 2
 Wednesday = 3
 Thursday = 4
 Friday = 5
 Saturday = 6
 * @param {type} $
 * @param {type} Drupal
 * @param {type} window
 * @param {type} document
 * @param {type} undefined
 * @returns {undefined}
 */
(function ($, Drupal, window, document, undefined) {
    $(document).ready(function () {

        // if now more than 15pm we will disable current day
        $('#datepicker-schedule').find("input").datepicker({
            minDate: 1,
            dateFormat: 'dd M y',
            changeMonth: false,
            changeYear: false,
            beforeShowDay: function (date) {
                var currentDay = new Date();
                var day = currentDay.getDay();
                var hours = currentDay.getHours();
                var day = date.getDay();

                if (hours >= 15) {
                    var ds = [day !== 1 && day !== 0 && day !== 6 && day !== currentDay, ""]
                    return ds;
                } else {
                    var ds = [day !== 1 && day !== 0 && day !== 6, ""];
                    return ds;
                }
            }
        });
        //add default date
        $('#edit-delivery-delivery-pane-field-display').find("input").datepicker("setDate", new Date());
        //END add default value

    });

})(jQuery, Drupal, this, this.document);
