Array.prototype.intersect = function(...a) {
  return [this,...a].reduce((p,c) => p.filter(e => c.includes(e)));
}
var arrs = [[0,2,4,6,8],[4,5,6,7],[4,6]],
     arr = [0,1,2,3,4,5,6,7,8,9];

document.write("<pre>" + JSON.stringify(arr.intersect(...arrs)) + "</pre>");