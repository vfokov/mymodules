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
                $('td').each(function(){
                    if( $(this).find('a').text() == man[$i] ) $(this).addClass('ui-datepicker-unselectable ui-state-disabled');
                    if( $(this).find('a').text() == man[$i] ) $(this).removeAttr('onclick').css('pointer-events', 'none');

                });
                $i++;
            }
        })
    });

})(jQuery, Drupal, this, this.document);