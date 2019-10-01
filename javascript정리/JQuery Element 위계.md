# JQuery Element 위계

```javascript
//앞으로 JQuery Object를 Qbject 라 줄인다
//앞으로 DOM Element를 Delement 라 줄인다

document.querySelector('div')
//return Delement

$('div')
//return Qbject

$('div')[0]
//return Delement

$($('div')[0])
//return Qbject




/*Delement family*/
var d = document.querySelector('div');
//return Delement

d.childElementCount
//return int

d.firstElementChild
d.lastElementChild
d.parentElement
d.nextElementSibling
d.previousElementSibling
//return Delement

d.children
//return HTMLCollection




/*Qbject family*/
var d = $('div');
//return Qbject

d.children()
d.parent()
d.parents()
d.siblings()
d.next()
d.prev()
d.find()
//return Qbject

```

