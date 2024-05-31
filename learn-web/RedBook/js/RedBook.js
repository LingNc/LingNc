window.onresize = function () {
    // 在这里编写你的处理代码
    console.log('窗口大小改变了！');
    // 例如，你可以根据新的窗口大小调整布局或执行其他操作
    re_position();
};
window.onload = function () {
    re_position();
};
function re_position() {
    var global = document.getElementById("global"); // 修正方法名
    // 获取global的左右margin的值
    var computedStyle = window.getComputedStyle(global); // 使用getComputedStyle获取计算后的样式
    var margin = parseInt(computedStyle.marginLeft); // 注意转换为数值类型

    // 获取left-page
    var left_page = document.getElementById("left-page");
    // 获取top
    var top = document.getElementById("top");

    // 获取global的宽度
    var width = global.offsetWidth; // 更改为offsetWidth以获取包括padding、border的总宽度

    // 把top的宽度设置为global的宽度
    top.style.width = width + 'px'; // 使用style属性，并添加单位'px'

    // 把top和left-page的left定位设为margin
    top.style.left = margin + 'px';
    left_page.style.left = margin + 'px'; // 同样为style属性并加'px'
}