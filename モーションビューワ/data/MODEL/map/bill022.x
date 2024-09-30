xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 144;
 -189.97771;458.10303;-146.49974;,
 -94.98900;458.10303;-146.49974;,
 -94.98900;343.17935;-146.49974;,
 -189.97771;343.17935;-146.49974;,
 0.00000;458.10303;-146.49974;,
 0.00000;343.17935;-146.49974;,
 94.98900;458.10303;-146.49974;,
 94.98900;343.17935;-146.49974;,
 189.97771;458.10303;-146.49974;,
 189.97771;343.17935;-146.49974;,
 -94.98900;228.25537;-146.49974;,
 -189.97771;228.25537;-146.49974;,
 0.00000;228.25537;-146.49974;,
 94.98900;228.25537;-146.49974;,
 189.97771;228.25537;-146.49974;,
 -94.98900;113.33165;-146.49974;,
 -189.97771;113.33165;-146.49974;,
 0.00000;113.33165;-146.49974;,
 94.98900;113.33165;-146.49974;,
 189.97771;113.33165;-146.49974;,
 -94.98900;-1.59190;-146.49974;,
 -189.97771;-1.59190;-146.49974;,
 0.00000;-1.59190;-146.49974;,
 94.98900;-1.59190;-146.49974;,
 189.97771;-1.59190;-146.49974;,
 189.97771;458.10303;-146.49974;,
 189.97771;458.10303;-73.24965;,
 189.97771;343.17935;-73.24965;,
 189.97771;343.17935;-146.49974;,
 189.97771;458.10303;0.00000;,
 189.97771;343.17935;0.00000;,
 189.97771;458.10303;73.24965;,
 189.97771;343.17935;73.24965;,
 189.97771;458.10303;146.49974;,
 189.97771;343.17935;146.49974;,
 189.97771;228.25537;-73.24965;,
 189.97771;228.25537;-146.49974;,
 189.97771;228.25537;0.00000;,
 189.97771;228.25537;73.24965;,
 189.97771;228.25537;146.49974;,
 189.97771;113.33165;-73.24965;,
 189.97771;113.33165;-146.49974;,
 189.97771;113.33165;0.00000;,
 189.97771;113.33165;73.24965;,
 189.97771;113.33165;146.49974;,
 189.97771;-1.59190;-73.24965;,
 189.97771;-1.59190;-146.49974;,
 189.97771;-1.59190;-0.00000;,
 189.97771;-1.59190;73.24965;,
 189.97771;-1.59190;146.49974;,
 189.97771;458.10303;146.49974;,
 94.98900;458.10303;146.49974;,
 94.98900;343.17935;146.49974;,
 189.97771;343.17935;146.49974;,
 0.00000;458.10303;146.49974;,
 0.00000;343.17935;146.49974;,
 -94.98900;458.10303;146.49974;,
 -94.98900;343.17935;146.49974;,
 -189.97771;458.10303;146.49974;,
 -189.97771;343.17935;146.49974;,
 94.98900;228.25537;146.49974;,
 189.97771;228.25537;146.49974;,
 0.00000;228.25537;146.49974;,
 -94.98900;228.25537;146.49974;,
 -189.97771;228.25537;146.49974;,
 94.98900;113.33165;146.49974;,
 189.97771;113.33165;146.49974;,
 0.00000;113.33165;146.49974;,
 -94.98900;113.33165;146.49974;,
 -189.97771;113.33165;146.49974;,
 94.98900;-1.59190;146.49974;,
 189.97771;-1.59190;146.49974;,
 0.00000;-1.59190;146.49974;,
 -94.98900;-1.59190;146.49974;,
 -189.97771;-1.59190;146.49974;,
 -189.97771;458.10303;146.49974;,
 -189.97771;458.10303;73.24965;,
 -189.97771;343.17935;73.24965;,
 -189.97771;343.17935;146.49974;,
 -189.97771;458.10303;0.00000;,
 -189.97771;343.17935;0.00000;,
 -189.97771;458.10303;-73.24965;,
 -189.97771;343.17935;-73.24965;,
 -189.97771;458.10303;-146.49974;,
 -189.97771;343.17935;-146.49974;,
 -189.97771;228.25537;73.24965;,
 -189.97771;228.25537;146.49974;,
 -189.97771;228.25537;0.00000;,
 -189.97771;228.25537;-73.24965;,
 -189.97771;228.25537;-146.49974;,
 -189.97771;113.33165;73.24965;,
 -189.97771;113.33165;146.49974;,
 -189.97771;113.33165;0.00000;,
 -189.97771;113.33165;-73.24965;,
 -189.97771;113.33165;-146.49974;,
 -189.97771;-1.59190;73.24965;,
 -189.97771;-1.59190;146.49974;,
 -189.97771;-1.59190;0.00000;,
 -189.97771;-1.59190;-73.24965;,
 -189.97771;-1.59190;-146.49974;,
 -94.98900;458.10303;146.49974;,
 -94.98900;458.10303;73.24965;,
 -189.97771;458.10303;73.24965;,
 0.00000;458.10303;73.24965;,
 94.98900;458.10303;146.49974;,
 94.98900;458.10303;73.24965;,
 189.97771;458.10303;73.24965;,
 -94.98900;458.10303;0.00000;,
 -189.97771;458.10303;0.00000;,
 0.00000;458.10303;0.00000;,
 94.98900;458.10303;0.00000;,
 189.97771;458.10303;0.00000;,
 -94.98900;458.10303;-73.24965;,
 -189.97771;458.10303;-73.24965;,
 0.00000;458.10303;-73.24965;,
 94.98900;458.10303;-73.24965;,
 189.97771;458.10303;-73.24965;,
 -94.98900;458.10303;-146.49974;,
 -189.97771;458.10303;-146.49974;,
 0.00000;458.10303;-146.49974;,
 94.98900;458.10303;-146.49974;,
 189.97771;458.10303;-146.49974;,
 -189.97771;-1.59190;73.24965;,
 -94.98900;-1.59190;73.24965;,
 -94.98900;-1.59190;146.49974;,
 0.00000;-1.59190;73.24965;,
 94.98900;-1.59190;73.24965;,
 94.98900;-1.59190;146.49974;,
 189.97771;-1.59190;73.24965;,
 -189.97771;-1.59190;0.00000;,
 -94.98900;-1.59190;0.00000;,
 0.00000;-1.59190;-0.00000;,
 94.98900;-1.59190;-0.00000;,
 189.97771;-1.59190;-0.00000;,
 -189.97771;-1.59190;-73.24965;,
 -94.98900;-1.59190;-73.24965;,
 0.00000;-1.59190;-73.24965;,
 94.98900;-1.59190;-73.24965;,
 189.97771;-1.59190;-73.24965;,
 -189.97771;-1.59190;-146.49974;,
 -94.98900;-1.59190;-146.49974;,
 0.00000;-1.59190;-146.49974;,
 94.98900;-1.59190;-146.49974;,
 189.97771;-1.59190;-146.49974;;
 
 96;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;4,6,7,5;,
 4;6,8,9,7;,
 4;3,2,10,11;,
 4;2,5,12,10;,
 4;5,7,13,12;,
 4;7,9,14,13;,
 4;11,10,15,16;,
 4;10,12,17,15;,
 4;12,13,18,17;,
 4;13,14,19,18;,
 4;16,15,20,21;,
 4;15,17,22,20;,
 4;17,18,23,22;,
 4;18,19,24,23;,
 4;25,26,27,28;,
 4;26,29,30,27;,
 4;29,31,32,30;,
 4;31,33,34,32;,
 4;28,27,35,36;,
 4;27,30,37,35;,
 4;30,32,38,37;,
 4;32,34,39,38;,
 4;36,35,40,41;,
 4;35,37,42,40;,
 4;37,38,43,42;,
 4;38,39,44,43;,
 4;41,40,45,46;,
 4;40,42,47,45;,
 4;42,43,48,47;,
 4;43,44,49,48;,
 4;50,51,52,53;,
 4;51,54,55,52;,
 4;54,56,57,55;,
 4;56,58,59,57;,
 4;53,52,60,61;,
 4;52,55,62,60;,
 4;55,57,63,62;,
 4;57,59,64,63;,
 4;61,60,65,66;,
 4;60,62,67,65;,
 4;62,63,68,67;,
 4;63,64,69,68;,
 4;66,65,70,71;,
 4;65,67,72,70;,
 4;67,68,73,72;,
 4;68,69,74,73;,
 4;75,76,77,78;,
 4;76,79,80,77;,
 4;79,81,82,80;,
 4;81,83,84,82;,
 4;78,77,85,86;,
 4;77,80,87,85;,
 4;80,82,88,87;,
 4;82,84,89,88;,
 4;86,85,90,91;,
 4;85,87,92,90;,
 4;87,88,93,92;,
 4;88,89,94,93;,
 4;91,90,95,96;,
 4;90,92,97,95;,
 4;92,93,98,97;,
 4;93,94,99,98;,
 4;75,100,101,102;,
 4;100,54,103,101;,
 4;54,104,105,103;,
 4;104,33,106,105;,
 4;102,101,107,108;,
 4;101,103,109,107;,
 4;103,105,110,109;,
 4;105,106,111,110;,
 4;108,107,112,113;,
 4;107,109,114,112;,
 4;109,110,115,114;,
 4;110,111,116,115;,
 4;113,112,117,118;,
 4;112,114,119,117;,
 4;114,115,120,119;,
 4;115,116,121,120;,
 4;122,123,124,96;,
 4;123,125,72,124;,
 4;125,126,127,72;,
 4;126,128,49,127;,
 4;129,130,123,122;,
 4;130,131,125,123;,
 4;131,132,126,125;,
 4;132,133,128,126;,
 4;134,135,130,129;,
 4;135,136,131,130;,
 4;136,137,132,131;,
 4;137,138,133,132;,
 4;139,140,135,134;,
 4;140,141,136,135;,
 4;141,142,137,136;,
 4;142,143,138,137;;
 
 MeshMaterialList {
  1;
  96;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0;;
  Material {
   0.800000;0.734400;0.602400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  6;
  0.000000;0.000000;-1.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;0.000000;1.000000;,
  -1.000000;0.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;;
  96;
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;1,1,1,1;,
  4;1,1,1,1;,
  4;1,1,1,1;,
  4;1,1,1,1;,
  4;1,1,1,1;,
  4;1,1,1,1;,
  4;1,1,1,1;,
  4;1,1,1,1;,
  4;1,1,1,1;,
  4;1,1,1,1;,
  4;1,1,1,1;,
  4;1,1,1,1;,
  4;1,1,1,1;,
  4;1,1,1,1;,
  4;1,1,1,1;,
  4;1,1,1,1;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;3,3,3,3;,
  4;3,3,3,3;,
  4;3,3,3,3;,
  4;3,3,3,3;,
  4;3,3,3,3;,
  4;3,3,3,3;,
  4;3,3,3,3;,
  4;3,3,3,3;,
  4;3,3,3,3;,
  4;3,3,3,3;,
  4;3,3,3,3;,
  4;3,3,3,3;,
  4;3,3,3,3;,
  4;3,3,3,3;,
  4;3,3,3,3;,
  4;3,3,3,3;,
  4;4,4,4,4;,
  4;4,4,4,4;,
  4;4,4,4,4;,
  4;4,4,4,4;,
  4;4,4,4,4;,
  4;4,4,4,4;,
  4;4,4,4,4;,
  4;4,4,4,4;,
  4;4,4,4,4;,
  4;4,4,4,4;,
  4;4,4,4,4;,
  4;4,4,4,4;,
  4;4,4,4,4;,
  4;4,4,4,4;,
  4;4,4,4,4;,
  4;4,4,4,4;,
  4;5,5,5,5;,
  4;5,5,5,5;,
  4;5,5,5,5;,
  4;5,5,5,5;,
  4;5,5,5,5;,
  4;5,5,5,5;,
  4;5,5,5,5;,
  4;5,5,5,5;,
  4;5,5,5,5;,
  4;5,5,5,5;,
  4;5,5,5,5;,
  4;5,5,5,5;,
  4;5,5,5,5;,
  4;5,5,5,5;,
  4;5,5,5,5;,
  4;5,5,5,5;;
 }
 MeshTextureCoords {
  144;
  0.000000;0.000000;,
  0.250000;0.000000;,
  0.250000;0.250000;,
  0.000000;0.250000;,
  0.500000;0.000000;,
  0.500000;0.250000;,
  0.750000;0.000000;,
  0.750000;0.250000;,
  1.000000;0.000000;,
  1.000000;0.250000;,
  0.250000;0.500000;,
  0.000000;0.500000;,
  0.500000;0.500000;,
  0.750000;0.500000;,
  1.000000;0.500000;,
  0.250000;0.750000;,
  0.000000;0.750000;,
  0.500000;0.750000;,
  0.750000;0.750000;,
  1.000000;0.750000;,
  0.250000;1.000000;,
  0.000000;1.000000;,
  0.500000;1.000000;,
  0.750000;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.250000;0.000000;,
  0.250000;0.250000;,
  0.000000;0.250000;,
  0.500000;0.000000;,
  0.500000;0.250000;,
  0.750000;0.000000;,
  0.750000;0.250000;,
  1.000000;0.000000;,
  1.000000;0.250000;,
  0.250000;0.500000;,
  0.000000;0.500000;,
  0.500000;0.500000;,
  0.750000;0.500000;,
  1.000000;0.500000;,
  0.250000;0.750000;,
  0.000000;0.750000;,
  0.500000;0.750000;,
  0.750000;0.750000;,
  1.000000;0.750000;,
  0.250000;1.000000;,
  0.000000;1.000000;,
  0.500000;1.000000;,
  0.750000;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.250000;0.000000;,
  0.250000;0.250000;,
  0.000000;0.250000;,
  0.500000;0.000000;,
  0.500000;0.250000;,
  0.750000;0.000000;,
  0.750000;0.250000;,
  1.000000;0.000000;,
  1.000000;0.250000;,
  0.250000;0.500000;,
  0.000000;0.500000;,
  0.500000;0.500000;,
  0.750000;0.500000;,
  1.000000;0.500000;,
  0.250000;0.750000;,
  0.000000;0.750000;,
  0.500000;0.750000;,
  0.750000;0.750000;,
  1.000000;0.750000;,
  0.250000;1.000000;,
  0.000000;1.000000;,
  0.500000;1.000000;,
  0.750000;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.250000;0.000000;,
  0.250000;0.250000;,
  0.000000;0.250000;,
  0.500000;0.000000;,
  0.500000;0.250000;,
  0.750000;0.000000;,
  0.750000;0.250000;,
  1.000000;0.000000;,
  1.000000;0.250000;,
  0.250000;0.500000;,
  0.000000;0.500000;,
  0.500000;0.500000;,
  0.750000;0.500000;,
  1.000000;0.500000;,
  0.250000;0.750000;,
  0.000000;0.750000;,
  0.500000;0.750000;,
  0.750000;0.750000;,
  1.000000;0.750000;,
  0.250000;1.000000;,
  0.000000;1.000000;,
  0.500000;1.000000;,
  0.750000;1.000000;,
  1.000000;1.000000;,
  0.250000;0.000000;,
  0.250000;0.250000;,
  0.000000;0.250000;,
  0.500000;0.250000;,
  0.750000;0.000000;,
  0.750000;0.250000;,
  1.000000;0.250000;,
  0.250000;0.500000;,
  0.000000;0.500000;,
  0.500000;0.500000;,
  0.750000;0.500000;,
  1.000000;0.500000;,
  0.250000;0.750000;,
  0.000000;0.750000;,
  0.500000;0.750000;,
  0.750000;0.750000;,
  1.000000;0.750000;,
  0.250000;1.000000;,
  0.000000;1.000000;,
  0.500000;1.000000;,
  0.750000;1.000000;,
  1.000000;1.000000;,
  0.000000;0.750000;,
  0.250000;0.750000;,
  0.250000;1.000000;,
  0.500000;0.750000;,
  0.750000;0.750000;,
  0.750000;1.000000;,
  1.000000;0.750000;,
  0.000000;0.500000;,
  0.250000;0.500000;,
  0.500000;0.500000;,
  0.750000;0.500000;,
  1.000000;0.500000;,
  0.000000;0.250000;,
  0.250000;0.250000;,
  0.500000;0.250000;,
  0.750000;0.250000;,
  1.000000;0.250000;,
  0.000000;0.000000;,
  0.250000;0.000000;,
  0.500000;0.000000;,
  0.750000;0.000000;,
  1.000000;0.000000;;
 }
}
