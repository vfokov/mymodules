/**
 * Created by neo on 07.01.14.
 */
(function ($, Drupal, window, document, undefined) {
    $(document).ready(function () {
        var man = Drupal.settings.delivery;
        $('input').click(function(){
            $i = 0;
            while($i < man.length){
                console.log(man[$i]);
                if ($('.ui-datepicker-year').text() == man[$i].substr(0, 4)){
                    if(man[$i].indexOf($('.ui-datepicker-month').text())){
                        $('td').each(function () {
                            var days = man[$i].substr(man[$i].length-2,2);
                            if ($(this).find('a').text() == days) $(this).addClass('ui-datepicker-unselectable ui-state-disabled');
                            if ($(this).find('a').text() == days) $(this).removeAttr('onclick').css('pointer-events', 'none');

                        });
                    }
                }
                $i++;
            }
        });
    });

})(jQuery, Drupal, this, this.document);