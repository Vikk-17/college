const data = [
  {
    checkbox: document.getElementById("activateApple"),
    text: document.getElementById("appleText"),
    button: document.getElementById("appleButton"),
  },
  {
    checkbox: document.getElementById("activateOrange"),
    text: document.getElementById("orangeText"),
    button: document.getElementById("orangeButton"),
  },
  {
    checkbox: document.getElementById("activateBanana"),
    text: document.getElementById("bananaText"),
    button: document.getElementById("bananaButton"),
  },
];

for (let i in data) {
  data[i].checkbox.addEventListener("change", () => {
    if (data[i].checkbox.checked) {
      data[i].text.disabled = false;
      data[i].button.disabled = false;
    } else {
      data[i].text.disabled = true;
      data[i].button.disabled = true;
    }
  });
}

let totalCost = 0;

function addApple() {
  const totalAppleCost = Math.floor(parseInt(data[0].text.value, 10) * 0.83);
  totalCost += totalAppleCost;
  return totalCost;
}
function addOrange() {
  const totalOrangeCost = Math.floor(parseInt(data[1].text.value, 10) * 0.83);
  totalCost += totalOrangeCost;
  return totalCost;
}
function addBanana() {
  const totalBananaCost = Math.floor(parseInt(data[2].text.value, 10) * 0.83);
  totalCost += totalBananaCost;
  return totalCost;
}

function calculateCost() {
  totalCost = totalCost + (totalCost * 0.05)
  alert(`Your total cost is: ${totalCost} rupee`);
}
