const fotoItems = document.querySelectorAll('.foto-item');
const popupImg = document.querySelector('.popup-img');
const popupTitle = document.querySelector('.popup-title');
const prevBtn = document.querySelector('.prev-btn');
const nextBtn = document.querySelector('.next-btn');
let currentIndex = 0;

const myPopup = new bootstrap.Modal(document.getElementById('gallery-popup'));

function showImage(index) {
  const item = fotoItems[index];
  popupImg.src = item.src;
  popupTitle.textContent = item.alt;
  currentIndex = index;
  myPopup.show();
}

fotoItems.forEach((item, index) => {
  item.addEventListener('click', () => {
    showImage(index);
  });

  const caption = document.createElement('p');
  caption.textContent = item.alt;
  caption.classList.add('caption');
  item.parentElement.appendChild(caption);
});

prevBtn.addEventListener('click', () => {
  currentIndex = (currentIndex - 1 + fotoItems.length) % fotoItems.length;
  showImage(currentIndex);
});

nextBtn.addEventListener('click', () => {
  currentIndex = (currentIndex + 1) % fotoItems.length;
  showImage(currentIndex);
});
