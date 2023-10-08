// Create a base class for SVG shapes
class SVGShape {
  constructor(type) {
    this.type = type;
    this.attributes = {};
  }

  setAttribute(attribute, value) {
    this.attributes[attribute] = value;
  }

  generateHTML() {
    const attributesString = Object.entries(this.attributes)
      .map(([attr, value]) => `${attr}="${value}"`)
      .join(" ");
    return `<${this.type} ${attributesString}/>`;
  }
}

// Create specific SVG shape classes
class SVGRect extends SVGShape {
  constructor() {
    super("rect");
  }

  setX(x) {
    this.setAttribute("x", x);
  }

  setY(y) {
    this.setAttribute("y", y);
  }

  setWidth(width) {
    this.setAttribute("width", width);
  }

  setHeight(height) {
    this.setAttribute("height", height);
  }

  setRX(rx) {
    this.setAttribute("rx", rx);
  }

  setRY(ry) {
    this.setAttribute("ry", ry);
  }
}

class SVGCircle extends SVGShape {
  constructor() {
    super("circle");
  }

  setCX(cx) {
    this.setAttribute("cx", cx);
  }

  setCY(cy) {
    this.setAttribute("cy", cy);
  }

  setR(r) {
    this.setAttribute("r", r);
  }
}

// Example usage:
const svgRect = new SVGRect();
svgRect.setX(100);
svgRect.setY(100);
svgRect.setWidth(200);
svgRect.setHeight(100);
svgRect.setRX(10);
svgRect.setRY(10);

const svgCircle = new SVGCircle();
svgCircle.setCX(300);
svgCircle.setCY(300);
svgCircle.setR(50);

const svgElements = [svgRect, svgCircle];

// Generate HTML for all SVG elements
const svgHTML = svgElements.map((element) => element.generateHTML()).join("\n");

// Output the SVG HTML
console.log(svgHTML);
