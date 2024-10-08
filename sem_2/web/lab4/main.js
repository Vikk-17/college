// const data = [
//   {
//     checkbox: document.getElementById("activateApple"),
//     text: document.getElementById("appleText"),
//     button: document.getElementById("appleButton"),
//   },
//   {
//     checkbox: document.getElementById("activateOrange"),
//     text: document.getElementById("orangeText"),
//     button: document.getElementById("orangeButton"),
//   },
//   {
//     checkbox: document.getElementById("activateBanana"),
//     text: document.getElementById("bananaText"),
//     button: document.getElementById("bananaButton"),
//   },
// ];

// for (let i in data) {
//   data[i].checkbox.addEventListener("change", () => {
//     if (data[i].checkbox.checked) {
//       data[i].text.disabled = false;
//       data[i].button.disabled = false;
//     } else {
//       data[i].text.disabled = true;
//       data[i].button.disabled = true;
//     }
//   });
// }

// let totalCost = 0;

// function addApple() {
//   const totalAppleCost = Math.floor(parseInt(data[0].text.value, 10) * 0.83);
//   totalCost += totalAppleCost;
//   return totalCost;
// }
// function addOrange() {
//   const totalOrangeCost = Math.floor(parseInt(data[1].text.value, 10) * 0.83);
//   totalCost += totalOrangeCost;
//   return totalCost;
// }
// function addBanana() {
//   const totalBananaCost = Math.floor(parseInt(data[2].text.value, 10) * 0.83);
//   totalCost += totalBananaCost;
//   return totalCost;
// }

// function calculateCost() {
//   totalCost = totalCost + (totalCost * 0.05)
//   alert(`Your total cost is: ${totalCost} rupee`);
// }

const data = [
  { checkboxId: "activateApple", textId: "appleText", buttonId: "appleButton" },
  { checkboxId: "activateOrange", textId: "orangeText", buttonId: "orangeButton" },
  { checkboxId: "activateBanana", textId: "bananaText", buttonId: "bananaButton" },
];

let totalCost = 0;
const price = 0.83;

// Set up event listeners for each fruit
data.forEach((item, index) => {
  const checkbox = document.getElementById(item.checkboxId);
  const text = document.getElementById(item.textId);
  const button = document.getElementById(item.buttonId);

  // Enable/disable text input and button based on checkbox
  checkbox.addEventListener("change", () => {
    const isChecked = checkbox.checked;
    text.disabled = !isChecked;
    button.disabled = !isChecked;
  });

  // Add event listener for button to calculate cost
  button.onclick = () => addFruitCost(index);
});

// Generic function to add fruit cost
function addFruitCost(index) {
  const quantity = parseInt(document.getElementById(data[index].textId).value, 10) || 0;
  totalCost += Math.floor(quantity * price);
  //document.getElementById(data[index].textId).value = ''; // Clear input after adding
}

// Calculate total cost including tax
function calculateCost() {
  const finalCost = Math.floor(totalCost * 1.05); // Add 5% tax
  alert(`Your total cost is: ${finalCost} rupees`);
}
