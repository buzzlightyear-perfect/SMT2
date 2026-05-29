function openbox(url) {
  var box = document.getElementById('box');
  var shadow = document.getElementById('shadowing');
  var title = document.getElementById('boxtitle');
  var content = document.getElementById('boxcontent');

  shadow.style.display = 'block';

  title.innerHTML = url;

  content.style.padding = "0";
  content.innerHTML = "<img src='" + url + "' alt='Lightbox Image' style='width: 70%;' />";

  box.style.display = 'block';
}

function closebox() {
  document.getElementById('box').style.display = 'none';
  document.getElementById('shadowing').style.display = 'none';
}
