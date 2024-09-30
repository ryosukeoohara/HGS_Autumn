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
 157;
 -0.05897;4.62275;9.04536;,
 -0.06620;6.79265;9.64407;,
 -0.01601;-0.16072;7.96196;,
 -10.80479;6.57163;6.77530;,
 -10.45950;4.93824;6.75182;,
 -9.24215;-0.15789;5.62620;,
 10.86211;6.87346;6.77295;,
 10.33881;4.67803;6.74160;,
 9.19916;-0.09637;5.62133;,
 12.07568;6.93861;-0.18586;,
 12.03424;6.71502;-0.18650;,
 10.19401;0.40386;0.20017;,
 11.72915;6.80514;-6.44673;,
 10.92627;5.28463;-6.37596;,
 8.88387;1.42367;-6.11224;,
 -10.04156;-0.07943;-0.01850;,
 -11.32496;4.97521;-0.17461;,
 -9.34388;1.29207;-6.14411;,
 -11.73907;6.67028;-0.15012;,
 -11.57563;6.78184;-6.60040;,
 -10.98964;5.28323;-6.43175;,
 -9.24215;-0.15789;5.62620;,
 -10.45950;4.93824;6.75182;,
 -10.80479;6.57163;6.77530;,
 -9.95575;22.54700;7.00488;,
 -0.11855;23.84028;11.91547;,
 -0.13485;28.80933;11.39472;,
 -11.43985;27.44386;7.07526;,
 9.71664;22.61264;6.99970;,
 11.16807;27.51928;7.06929;,
 10.88790;21.22921;0.07405;,
 12.07473;27.62183;0.14381;,
 12.24007;24.30629;-6.30284;,
 11.16423;27.69651;-5.26358;,
 -12.52726;24.22367;-6.29630;,
 -10.87732;21.15661;0.07979;,
 -12.35084;27.54035;0.15027;,
 -11.44370;27.62109;-5.25761;,
 -9.95575;22.54700;7.00488;,
 -11.43985;27.44386;7.07526;,
 -0.15137;32.33992;9.82248;,
 -11.45701;32.37957;4.44187;,
 11.15091;32.45499;4.43591;,
 12.05842;32.51869;0.21420;,
 11.14852;32.57169;-3.15428;,
 -12.36716;32.43721;0.22064;,
 -11.45941;32.49627;-3.14832;,
 -11.45701;32.37957;4.44187;,
 -0.16352;34.85861;8.42982;,
 -5.68410;34.88512;6.17773;,
 5.35576;34.92230;6.15024;,
 7.09473;35.01914;0.48986;,
 5.19719;35.09205;-3.73436;,
 7.09473;35.01914;0.48986;,
 -7.57736;34.96970;0.49378;,
 -5.68257;35.05525;-3.73146;,
 -5.68410;34.88512;6.17773;,
 -7.56821;34.96970;0.49377;,
 -0.01601;-0.16072;7.96196;,
 -9.24215;-0.15789;5.62620;,
 -0.01849;-0.04600;-0.02115;,
 9.19916;-0.09637;5.62133;,
 10.19401;0.40386;0.20017;,
 8.88387;1.42367;-6.11224;,
 -10.04156;-0.07943;-0.01850;,
 -9.34388;1.29207;-6.14411;,
 -3.60807;40.18487;5.47351;,
 0.16285;40.16208;7.30546;,
 0.06413;40.35211;1.72215;,
 3.57933;40.21035;5.37579;,
 5.65998;40.28927;1.84308;,
 4.60626;40.33289;-1.43672;,
 0.15998;40.20830;-2.97585;,
 -4.61257;40.30274;-1.47638;,
 -5.63418;40.25158;1.84657;,
 -0.02203;0.54322;-5.97945;,
 -0.02203;0.54322;-5.97945;,
 -0.02203;0.54322;-5.97945;,
 -0.07114;6.89961;-7.73408;,
 -0.06313;4.50324;-7.10010;,
 -0.07114;6.89961;-7.73408;,
 -0.06313;4.50324;-7.10010;,
 -0.02203;0.54322;-5.97945;,
 -0.12431;22.80280;-8.17399;,
 -0.14033;27.68626;-7.17153;,
 -0.14033;27.68626;-7.17153;,
 -0.15415;31.83772;-7.06744;,
 -0.15415;31.83772;-7.06744;,
 -5.67343;35.05526;-3.73146;,
 0.07511;35.07132;-5.27179;,
 -0.15415;31.83772;-7.06744;,
 5.19719;35.09205;-3.73436;,
 -11.89894;11.74745;6.84968;,
 -0.08264;11.72710;10.79893;,
 -0.09741;16.15832;9.77867;,
 -11.40202;16.08849;6.91206;,
 -13.00824;11.86545;-0.07505;,
 -11.89894;11.74745;6.84968;,
 -11.40202;16.08849;6.91206;,
 -12.65339;16.35622;-0.01055;,
 -12.64087;16.73404;-6.40075;,
 -13.09089;11.92410;-4.34101;,
 -13.00390;12.13409;-7.89149;,
 -12.55691;16.65485;-6.73280;,
 -13.00405;12.11600;-7.97157;,
 -0.08777;11.87288;-7.87165;,
 -0.08836;12.05116;-7.87658;,
 -0.10275;16.35553;-7.99565;,
 -0.08836;12.05116;-7.87658;,
 10.54798;12.18000;-7.58312;,
 -0.08777;11.87288;-7.87165;,
 13.26617;12.18715;-7.58303;,
 -0.10275;16.35553;-7.99565;,
 11.82842;16.36189;-6.94367;,
 11.80740;16.73173;-6.56680;,
 12.68249;17.01398;-0.00900;,
 13.25635;12.21156;-7.60430;,
 13.31902;11.77245;-0.08434;,
 11.95080;11.44085;6.83822;,
 11.20459;16.55936;6.91179;,
 -11.00840;21.14148;-3.91155;,
 -10.11917;20.85021;-6.06872;,
 -10.75665;21.89079;-7.73015;,
 -10.11571;20.78816;-6.12532;,
 9.33154;20.42360;-6.88543;,
 -0.12431;22.80280;-8.17399;,
 9.78136;20.91544;-6.87858;,
 10.43023;21.90781;-7.75515;,
 11.01700;21.21034;-3.91743;,
 -0.13585;35.40355;8.20442;,
 4.80608;35.42147;6.13480;,
 6.59506;34.96924;1.56184;,
 5.58087;35.07545;-2.78539;,
 0.06644;35.07387;-5.30760;,
 -5.93613;35.17620;-2.93420;,
 -7.10735;35.54339;1.48684;,
 -4.85290;35.25777;6.26253;,
 7.09473;35.01914;0.48986;,
 5.19719;35.09205;-3.73436;,
 5.35576;34.92230;6.15024;,
 6.59506;34.96924;1.56184;,
 -5.67343;35.05526;-3.73146;,
 0.06644;35.07387;-5.30760;,
 4.80608;35.42147;6.13480;,
 0.07511;35.07132;-5.27179;,
 -0.16352;34.85861;8.42982;,
 -0.13585;35.40355;8.20442;,
 -4.85290;35.25777;6.26253;,
 -5.68410;34.88512;6.17773;,
 -5.93613;35.17620;-2.93420;,
 -7.10735;35.54339;1.48684;,
 -7.56821;34.96970;0.49377;,
 -5.68257;35.05525;-3.73146;,
 -7.57736;34.96970;0.49378;,
 5.58087;35.07545;-2.78539;,
 -7.57736;34.96970;0.49378;,
 -5.68257;35.05525;-3.73146;;
 
 162;
 3;0,1,2;,
 3;1,3,2;,
 3;2,3,4;,
 3;4,5,2;,
 3;6,1,7;,
 3;7,1,8;,
 3;8,1,2;,
 3;1,0,2;,
 3;9,6,10;,
 3;10,6,11;,
 3;11,6,8;,
 3;6,7,8;,
 3;12,9,13;,
 3;13,9,14;,
 3;14,9,10;,
 3;10,11,14;,
 3;15,16,17;,
 3;16,18,17;,
 3;18,19,20;,
 3;20,17,18;,
 3;21,22,15;,
 3;22,23,15;,
 3;23,18,15;,
 3;18,16,15;,
 4;24,25,26,27;,
 4;25,28,29,26;,
 4;28,30,31,29;,
 4;30,32,33,31;,
 4;34,35,36,37;,
 4;35,38,39,36;,
 4;27,26,40,41;,
 4;26,29,42,40;,
 4;29,31,43,42;,
 4;31,33,44,43;,
 4;37,36,45,46;,
 4;36,39,47,45;,
 4;41,40,48,49;,
 4;40,42,50,48;,
 4;42,43,51,50;,
 4;43,44,52,53;,
 4;46,45,54,55;,
 4;45,47,56,57;,
 3;58,59,60;,
 3;61,58,60;,
 3;62,61,60;,
 3;63,62,60;,
 3;64,65,60;,
 3;59,64,60;,
 3;66,67,68;,
 3;67,69,68;,
 3;69,70,68;,
 3;70,71,68;,
 3;71,72,68;,
 3;72,73,68;,
 3;73,74,68;,
 3;74,66,68;,
 3;65,75,60;,
 3;76,63,60;,
 3;17,20,77;,
 3;20,19,77;,
 3;19,78,77;,
 3;78,79,77;,
 3;80,12,81;,
 3;81,12,82;,
 3;82,12,13;,
 3;13,14,82;,
 4;83,34,37,84;,
 4;32,83,85,33;,
 4;84,37,46,86;,
 4;87,46,88,89;,
 4;44,90,89,91;,
 4;33,84,90,44;,
 4;92,93,94,95;,
 4;96,97,98,99;,
 3;99,100,96;,
 3;96,100,101;,
 3;101,100,102;,
 3;100,103,102;,
 3;103,104,102;,
 3;105,104,106;,
 3;106,104,107;,
 3;104,103,107;,
 3;108,109,110;,
 4;111,108,112,113;,
 3;114,115,113;,
 3;113,115,111;,
 3;116,111,117;,
 3;111,115,117;,
 4;118,117,115,119;,
 4;93,118,119,94;,
 4;119,115,30,28;,
 4;94,119,28,25;,
 4;95,94,25,24;,
 4;99,98,38,35;,
 3;35,34,120;,
 3;120,34,121;,
 3;34,122,121;,
 3;107,103,83;,
 3;83,103,123;,
 3;83,123,121;,
 3;83,121,34;,
 3;121,122,34;,
 3;113,112,124;,
 3;112,125,124;,
 3;124,125,126;,
 3;126,125,127;,
 3;125,32,127;,
 3;124,126,113;,
 3;126,128,113;,
 3;113,128,114;,
 3;114,128,115;,
 3;128,30,115;,
 4;6,9,117,118;,
 4;1,6,118,93;,
 4;3,1,93,92;,
 4;18,23,97,96;,
 3;18,96,19;,
 3;96,101,19;,
 3;101,102,19;,
 3;102,104,19;,
 4;78,19,104,105;,
 3;111,12,109;,
 3;109,12,110;,
 3;12,80,110;,
 3;109,108,111;,
 3;116,117,111;,
 3;111,117,12;,
 3;117,9,12;,
 3;35,120,99;,
 3;99,120,100;,
 3;120,121,100;,
 3;121,123,100;,
 3;123,103,100;,
 3;127,32,126;,
 3;32,30,128;,
 3;128,126,32;,
 4;129,130,69,67;,
 4;130,131,70,69;,
 4;131,132,71,70;,
 4;132,133,72,71;,
 4;133,134,73,72;,
 4;134,135,74,73;,
 4;135,136,66,74;,
 4;136,129,67,66;,
 3;137,138,139;,
 3;140,141,142;,
 3;139,138,143;,
 3;138,144,143;,
 3;139,143,145;,
 3;143,146,145;,
 3;146,147,145;,
 3;145,147,148;,
 3;142,141,149;,
 3;147,150,148;,
 3;148,150,151;,
 3;141,152,149;,
 3;152,153,149;,
 3;149,153,150;,
 3;153,151,150;,
 3;142,154,140;,
 3;155,45,57;,
 3;46,156,88;;
 
 MeshMaterialList {
  6;
  162;
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2;;
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "Documentsneet.png";
   }
  }
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "neett.jpg";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "C:\\Users\\student\\Documents\\Photoshop\\neett.png";
   }
  }
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "UV_Grid.png";
   }
  }
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "UV_Grid.png";
   }
  }
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  168;
  0.961573;-0.273231;0.026884;,
  0.926407;-0.313286;-0.208861;,
  0.009282;-0.995102;-0.098412;,
  -0.949647;-0.288523;-0.122169;,
  -0.967741;-0.239418;0.078462;,
  -0.777251;-0.028020;0.628567;,
  0.000325;-0.061233;0.998123;,
  0.769624;-0.010159;0.638417;,
  0.996064;0.042796;0.077621;,
  0.929089;-0.360193;-0.083995;,
  -0.054789;0.101706;-0.993305;,
  -0.915067;-0.396992;-0.071060;,
  -0.997498;0.001676;0.070681;,
  -0.795310;0.048434;0.604266;,
  -0.000379;0.220354;0.975420;,
  0.793457;0.058809;0.605778;,
  0.999501;-0.018429;0.025662;,
  0.991347;0.062134;-0.115627;,
  -0.001004;0.237962;-0.971274;,
  -0.992842;0.048441;-0.109174;,
  -0.999117;-0.033223;0.025729;,
  0.998988;0.039460;-0.021604;,
  0.976202;0.040743;-0.213002;,
  -0.976564;0.034228;-0.212488;,
  -0.999240;0.032794;-0.021076;,
  -0.426690;0.877203;-0.220116;,
  -0.590454;0.773583;-0.230071;,
  -0.003178;0.999941;0.010387;,
  -0.799915;-0.581113;-0.149812;,
  -0.535761;0.508759;-0.673887;,
  0.030571;-0.255851;-0.966233;,
  0.082258;-0.008471;-0.996575;,
  -0.025273;-0.652479;-0.757385;,
  -0.811018;-0.582553;-0.053680;,
  -0.995297;-0.080442;0.053968;,
  -0.997278;-0.071500;0.018014;,
  0.024160;-0.004263;-0.999699;,
  0.025667;-0.084592;-0.996085;,
  0.027665;-0.071183;-0.997080;,
  -0.923120;-0.384229;-0.014743;,
  -0.997564;-0.032240;-0.061863;,
  0.020346;-0.145258;-0.989185;,
  0.967820;0.251625;-0.003142;,
  -0.970801;0.229004;0.071431;,
  -0.938858;0.269536;-0.214233;,
  0.014324;0.054160;-0.998429;,
  0.047225;0.049387;-0.997663;,
  0.970612;-0.232247;-0.063038;,
  -0.969223;-0.241734;-0.046607;,
  -0.926684;-0.374812;-0.027796;,
  -0.930406;0.090834;0.355098;,
  0.882539;-0.468648;-0.038653;,
  -0.991043;0.043968;-0.126102;,
  0.979512;0.083924;-0.183067;,
  -0.934288;0.295638;-0.199258;,
  0.950670;0.254003;-0.178070;,
  -0.995581;-0.093721;-0.005979;,
  0.952738;-0.303019;-0.021686;,
  0.942064;-0.333423;-0.036653;,
  0.018011;-0.173005;-0.984756;,
  -0.959640;-0.281183;-0.005276;,
  -0.960654;-0.276129;0.029933;,
  -0.002767;0.999416;0.034064;,
  0.007825;0.999481;0.031251;,
  0.010813;0.999758;0.019168;,
  -0.003138;0.999939;-0.010597;,
  -0.003531;0.999523;-0.030669;,
  -0.003595;0.999942;-0.010178;,
  -0.017222;0.999672;0.018966;,
  -0.013800;0.999423;0.031047;,
  0.006901;0.308015;0.951356;,
  0.601407;0.426673;0.675470;,
  0.970297;0.225505;0.087589;,
  0.716584;0.299527;-0.629913;,
  -0.002807;0.657990;-0.753022;,
  -0.686845;0.561253;-0.461778;,
  -0.823106;0.555401;0.118436;,
  -0.513125;0.491663;0.703542;,
  -0.187701;-0.154221;0.970043;,
  -0.236851;-0.263149;0.935229;,
  0.992936;0.034621;-0.113487;,
  -0.222830;-0.142030;0.964456;,
  0.224409;-0.248423;0.942298;,
  0.231840;-0.173097;0.957229;,
  0.267317;-0.114259;0.956811;,
  -0.000983;0.435547;0.900166;,
  -0.640443;0.503323;0.580085;,
  0.636442;0.510884;0.577875;,
  0.004350;0.438166;0.898883;,
  -0.556446;0.648201;0.519810;,
  0.423778;0.799663;0.425383;,
  0.294523;0.955637;0.003659;,
  -0.760357;0.601237;0.245706;,
  0.015603;-0.995907;-0.089027;,
  0.002180;0.342011;-0.939693;,
  -0.110918;0.895320;-0.431393;,
  0.005309;0.466233;-0.884646;,
  0.307855;0.923898;-0.227241;,
  -0.002275;-0.015487;0.999877;,
  -0.284235;-0.015638;0.958627;,
  -0.001550;0.011227;0.999936;,
  -0.307927;0.008355;0.951373;,
  0.979722;-0.057558;0.191915;,
  0.957589;0.218550;0.187772;,
  0.078050;-0.190397;0.978600;,
  -0.096828;-0.195217;0.975968;,
  -0.992936;-0.034621;0.113487;,
  0.963108;-0.234936;0.131254;,
  0.967036;-0.243197;0.075468;,
  0.972752;-0.231843;-0.001506;,
  -0.957146;-0.257790;0.131969;,
  -0.966007;-0.232623;0.112770;,
  -0.967464;-0.222947;0.119617;,
  0.433113;0.901333;-0.003277;,
  0.343781;0.586123;-0.733672;,
  -0.380911;0.743774;-0.549278;,
  -0.448056;0.894004;-0.001561;,
  0.003332;-0.999891;-0.014370;,
  0.003331;-0.999891;-0.014370;,
  0.024516;-0.998500;-0.048963;,
  0.046386;-0.990912;-0.126263;,
  0.071811;-0.988439;-0.133538;,
  0.003282;-0.993142;-0.116871;,
  -0.037485;-0.986643;-0.158524;,
  0.012253;-0.066850;-0.997688;,
  0.001706;-0.091078;-0.995842;,
  -0.002037;-0.136990;-0.990570;,
  -0.049647;-0.173815;-0.983526;,
  0.055163;-0.166583;-0.984483;,
  0.104289;-0.261927;-0.959436;,
  -0.014699;-0.049575;-0.998662;,
  -0.008590;-0.063619;-0.997937;,
  -0.155592;0.038543;-0.987069;,
  -0.182761;0.233486;-0.955030;,
  0.104982;0.370177;-0.923010;,
  0.180785;0.234508;-0.955156;,
  -0.118172;-0.008566;-0.992956;,
  -0.985520;-0.065531;0.156383;,
  -0.970612;0.186239;0.152407;,
  -0.031416;0.019290;-0.999320;,
  -0.148359;0.177285;-0.972913;,
  0.921103;0.311030;-0.234159;,
  0.988241;0.147561;-0.040074;,
  0.998181;-0.023373;0.055574;,
  0.280034;-0.014077;0.959887;,
  0.305040;0.013020;0.952250;,
  -0.537615;0.402190;-0.741090;,
  0.811018;0.582553;0.053680;,
  0.075038;0.474458;-0.877074;,
  0.922554;-0.084096;-0.376592;,
  0.002476;-0.945578;0.325386;,
  0.923120;0.384229;0.014743;,
  0.812760;-0.579998;-0.054984;,
  0.690994;0.221825;0.687983;,
  0.014498;0.229967;0.973090;,
  0.021924;0.367810;-0.929642;,
  -0.673987;0.371734;-0.638400;,
  -0.946938;0.306981;0.095246;,
  -0.661970;0.252800;0.705612;,
  0.006040;-0.999762;-0.020967;,
  -0.000746;-0.999894;-0.014519;,
  0.005898;0.999434;-0.033126;,
  -0.024814;0.987140;-0.157922;,
  0.000912;-0.546615;0.837384;,
  0.000545;-0.866006;0.500034;,
  0.012825;-0.999542;-0.027412;,
  0.001083;-0.109256;0.994013;,
  0.000223;-0.222662;-0.974896;;
  162;
  3;80,80,80;,
  3;104,81,105;,
  3;105,81,78;,
  3;78,79,105;,
  3;84,104,83;,
  3;83,104,82;,
  3;82,104,105;,
  3;106,106,106;,
  3;57,107,47;,
  3;47,107,0;,
  3;0,107,108;,
  3;107,109,108;,
  3;58,57,51;,
  3;51,57,1;,
  3;1,57,47;,
  3;47,0,1;,
  3;4,48,3;,
  3;48,61,3;,
  3;61,60,49;,
  3;49,3,61;,
  3;110,111,4;,
  3;111,112,4;,
  3;112,61,4;,
  3;61,48,4;,
  4;5,6,14,13;,
  4;6,7,15,14;,
  4;7,8,16,15;,
  4;8,9,17,16;,
  4;11,12,20,19;,
  4;12,5,13,20;,
  4;13,14,85,86;,
  4;14,15,87,85;,
  4;15,16,21,87;,
  4;16,17,22,21;,
  4;19,20,24,23;,
  4;20,13,86,24;,
  4;86,85,88,89;,
  4;85,87,90,88;,
  4;87,113,91,90;,
  4;113,114,97,91;,
  4;115,116,26,25;,
  4;116,86,89,92;,
  3;117,118,93;,
  3;119,117,93;,
  3;120,119,93;,
  3;121,120,93;,
  3;122,123,93;,
  3;118,122,93;,
  3;69,62,27;,
  3;62,63,27;,
  3;63,64,27;,
  3;64,65,27;,
  3;65,66,27;,
  3;66,67,27;,
  3;67,68,27;,
  3;68,69,27;,
  3;123,2,93;,
  3;2,121,93;,
  3;124,125,126;,
  3;125,127,126;,
  3;127,59,126;,
  3;50,50,50;,
  3;59,128,129;,
  3;129,128,126;,
  3;126,128,130;,
  3;130,131,126;,
  4;10,132,133,18;,
  4;134,10,18,135;,
  4;18,133,136,94;,
  4;94,115,95,96;,
  4;114,94,96,97;,
  4;135,18,94,114;,
  4;99,98,100,101;,
  4;34,137,138,43;,
  3;43,54,34;,
  3;34,54,56;,
  3;56,54,40;,
  3;54,44,40;,
  3;44,35,40;,
  3;37,139,36;,
  3;36,139,45;,
  3;139,140,45;,
  3;36,41,37;,
  4;38,36,45,46;,
  3;55,42,141;,
  3;141,42,142;,
  3;39,39,39;,
  3;142,42,143;,
  4;102,143,42,103;,
  4;98,144,145,100;,
  4;103,42,8,7;,
  4;100,145,7,6;,
  4;101,100,6,5;,
  4;43,138,5,12;,
  3;12,11,52;,
  3;52,11,28;,
  3;11,33,28;,
  3;45,140,10;,
  3;10,140,29;,
  3;10,29,146;,
  3;10,146,132;,
  3;147,147,147;,
  3;46,45,31;,
  3;45,10,31;,
  3;31,10,30;,
  3;30,10,32;,
  3;10,134,148;,
  3;31,30,46;,
  3;149,53,141;,
  3;141,53,55;,
  3;55,53,42;,
  3;53,8,42;,
  4;107,57,143,102;,
  4;104,84,144,98;,
  4;81,104,98,99;,
  4;61,112,137,34;,
  3;61,34,60;,
  3;34,56,60;,
  3;56,40,60;,
  3;40,35,60;,
  4;59,127,139,37;,
  3;38,128,41;,
  3;41,128,37;,
  3;128,59,37;,
  3;150,150,150;,
  3;151,143,142;,
  3;142,143,58;,
  3;143,57,58;,
  3;12,52,43;,
  3;43,52,54;,
  3;52,146,54;,
  3;146,29,54;,
  3;29,44,54;,
  3;152,9,152;,
  3;9,8,53;,
  3;53,149,9;,
  4;70,71,153,154;,
  4;71,72,72,153;,
  4;72,73,73,72;,
  4;73,74,155,73;,
  4;74,75,156,155;,
  4;75,76,157,156;,
  4;76,77,158,157;,
  4;77,70,154,158;,
  3;91,97,90;,
  3;159,160,159;,
  3;90,97,71;,
  3;97,161,161;,
  3;90,71,88;,
  3;71,70,88;,
  3;70,77,88;,
  3;88,77,89;,
  3;74,95,162;,
  3;77,76,89;,
  3;89,76,92;,
  3;95,25,162;,
  3;25,26,75;,
  3;75,26,76;,
  3;163,163,164;,
  3;159,165,159;,
  3;163,166,163;,
  3;136,167,167;;
 }
 MeshTextureCoords {
  157;
  0.877355;0.895183;,
  0.877355;0.892634;,
  0.877355;0.900895;,
  0.868457;0.892898;,
  0.868457;0.894817;,
  0.868457;0.900895;,
  0.886254;0.892627;,
  0.886254;0.895204;,
  0.886254;0.900895;,
  0.895152;0.892581;,
  0.895152;0.895374;,
  0.895152;0.900895;,
  0.904733;0.893357;,
  0.904425;0.896755;,
  0.904050;0.900895;,
  0.930745;0.900895;,
  0.930745;0.894894;,
  0.919622;0.898665;,
  0.930745;0.892901;,
  0.919622;0.890996;,
  0.919622;0.892851;,
  0.939643;0.900895;,
  0.939643;0.894817;,
  0.939643;0.892898;,
  0.868457;0.874134;,
  0.877355;0.874134;,
  0.877355;0.847372;,
  0.868457;0.847372;,
  0.886254;0.874134;,
  0.886254;0.847372;,
  0.895152;0.874134;,
  0.895152;0.847372;,
  0.906274;0.876364;,
  0.904050;0.847372;,
  0.919622;0.871904;,
  0.930745;0.874134;,
  0.930745;0.847372;,
  0.919622;0.845142;,
  0.939643;0.874134;,
  0.939643;0.847372;,
  0.877355;0.820611;,
  0.868457;0.820611;,
  0.886254;0.820611;,
  0.895152;0.820611;,
  0.904050;0.820611;,
  0.930745;0.820611;,
  0.919622;0.817266;,
  0.939643;0.820611;,
  0.877355;0.793849;,
  0.868457;0.793849;,
  0.886254;0.793849;,
  0.895152;0.793849;,
  0.915656;0.786469;,
  0.902625;0.755009;,
  0.930745;0.793849;,
  0.921846;0.793849;,
  0.939643;0.793849;,
  0.930745;0.793849;,
  0.904050;0.989878;,
  0.935510;0.976846;,
  0.906016;0.942197;,
  0.872590;0.976846;,
  0.859559;0.945386;,
  0.872590;0.913927;,
  0.948541;0.945386;,
  0.935510;0.913927;,
  0.259070;0.054827;,
  0.223487;0.036071;,
  0.223487;0.092422;,
  0.188668;0.055633;,
  0.173623;0.090428;,
  0.186716;0.127113;,
  0.223487;0.147979;,
  0.260750;0.127577;,
  0.273545;0.090420;,
  0.919780;0.907411;,
  0.909135;0.905713;,
  0.912058;0.893759;,
  0.912100;0.886943;,
  0.912084;0.889546;,
  0.909129;0.895847;,
  0.908888;0.897774;,
  0.908499;0.900895;,
  0.912207;0.869674;,
  0.912207;0.842912;,
  0.910724;0.856293;,
  0.914431;0.811690;,
  0.911465;0.811690;,
  0.921846;0.793849;,
  0.912948;0.793849;,
  0.910279;0.825963;,
  0.904050;0.793849;,
  0.868457;0.886819;,
  0.877355;0.886839;,
  0.877355;0.881634;,
  0.868457;0.881720;,
  0.930745;0.886794;,
  0.939643;0.886819;,
  0.939643;0.881720;,
  0.930745;0.881520;,
  0.923514;0.879821;,
  0.926170;0.885949;,
  0.920052;0.884819;,
  0.919622;0.878907;,
  0.919622;0.884740;,
  0.912134;0.881543;,
  0.912135;0.881349;,
  0.912163;0.876675;,
  0.909645;0.891703;,
  0.905353;0.888169;,
  0.909627;0.891846;,
  0.905214;0.888054;,
  0.910077;0.888241;,
  0.905677;0.882951;,
  0.901994;0.882215;,
  0.895152;0.880847;,
  0.899124;0.887418;,
  0.895152;0.887003;,
  0.886254;0.887268;,
  0.886254;0.881255;,
  0.924369;0.874311;,
  0.919622;0.874138;,
  0.919622;0.873456;,
  0.919622;0.874185;,
  0.906085;0.878455;,
  0.910724;0.883054;,
  0.906089;0.878412;,
  0.906144;0.877799;,
  0.901363;0.876750;,
  0.223487;0.010796;,
  0.169625;0.035513;,
  0.151618;0.089548;,
  0.167684;0.145069;,
  0.223487;0.175383;,
  0.281365;0.147027;,
  0.299361;0.089387;,
  0.278780;0.034002;,
  0.014533;0.084668;,
  0.032190;0.127295;,
  0.032190;0.042042;,
  0.035751;0.087072;,
  0.117443;0.127295;,
  0.075994;0.135135;,
  0.045834;0.056816;,
  0.074816;0.144951;,
  0.074816;0.024385;,
  0.075994;0.042976;,
  0.106955;0.055970;,
  0.117443;0.042042;,
  0.108403;0.119257;,
  0.118479;0.086983;,
  0.135099;0.084668;,
  0.098065;0.128897;,
  0.115721;0.086271;,
  0.044747;0.118161;,
  0.930745;0.807230;,
  0.920734;0.805557;;
 }
}
