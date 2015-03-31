(function ($, Drupal, window, document, undefined) {
    $(document).ready(function () {
        $('#edit-delivery-manual').click(function(){
            $('#edit-delivery-manual').multiDatesPicker({dateFormat: "yy MM dd"});
        })
    });

})(jQuery, Drupal, this, this.document);