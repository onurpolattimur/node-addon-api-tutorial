const simpleMath = require("./build/Release/SimpleMathNodeAddon.node");
const simpleMathInstance = new simpleMath.SimpleMathNode();

try{
    console.log(simpleMathInstance.add(1,2));
    console.log(simpleMathInstance.substract(1,2));
    console.log(simpleMathInstance.multiply(4,2));
    console.log(simpleMathInstance.divide(9,3));
    console.log(simpleMathInstance.divide(12,0));
}catch(e){
    console.error(e.toString());
}
