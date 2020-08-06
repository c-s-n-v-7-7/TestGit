const name = "Slim Shady";
const age = 19;

console.log(`Hi My name is ${name} and my age is ${age}`);

const text = document.querySelector(".Xo");
//text.style.backgroundColor = "red";
changecolor = document.querySelector(".changecolor");
//text.classList.remove('change');

/*changecolor.addEventListener('click', function(){
text.classList.toggle("change");    
});*/

const userList = document.querySelector(".name-list li");
const listInput = document.querySelector(".list-input");
const addListButton = document.querySelector(".addListButton");

addListButton.addEventListener("click", function(){
const newLi = document.createElement("LI");
const liContent = document.createTextNode(listInput.value);
newLi.appendChild(liContent);
userList.appendChild(newLi);    
});