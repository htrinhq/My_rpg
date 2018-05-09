#version 130

uniform sampler2D texture;
uniform float clr_r;
uniform float clr_g;
uniform float clr_b;

void main()
{
    vec4 color = vec4(clr_r, clr_g, clr_b, 1.);
    gl_FragColor = color;
}