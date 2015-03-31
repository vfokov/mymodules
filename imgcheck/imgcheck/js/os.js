(function ($, Drupal, window, document, undefined) {
    $(document).ready(function mail_user() {
      //alert("Hello! I am an alert box!!");
	function img_find() {
    var imgs = document.getElementsByTagName("img");
    var imgSrcs = [];

    for (var i = 0; i < imgs.length; i++) {
        imgSrcs.push(imgs[i].src);
    }

    return imgSrcs;
}
	console.log(imgSrcs)
	alert("imgSrcs");
    });

})(jQuery, Drupal, this, this.document);
