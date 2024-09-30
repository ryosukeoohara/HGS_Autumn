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
 186;
 -2.19618;0.34013;-2.06237;,
 -2.85626;0.10686;-1.90932;,
 -2.70280;-0.34085;-1.77763;,
 -2.04453;-0.10089;-2.11075;,
 -3.12935;-0.96623;-2.31017;,
 -1.91975;-0.25814;-2.26880;,
 -3.07012;-1.13594;-2.68158;,
 -1.85746;-0.43895;-2.34195;,
 -3.13681;-0.93924;-3.03732;,
 -1.92089;-0.25397;-2.38139;,
 -3.29022;-0.49172;-3.16901;,
 -2.04701;-0.09197;-2.35126;,
 -3.44061;-0.05520;-2.99951;,
 -2.19732;0.34431;-2.17497;,
 -3.49980;0.11440;-2.62809;,
 -2.25940;0.52431;-2.08394;,
 -2.85626;0.10686;-1.90932;,
 -2.19618;0.34013;-2.06237;,
 -3.98707;-0.27245;-2.27623;,
 -3.83359;-0.72014;-2.14453;,
 -3.68327;-1.15647;-2.31404;,
 -3.62402;-1.32620;-2.68545;,
 -3.69073;-1.12948;-3.04120;,
 -3.84412;-0.68198;-3.17288;,
 -3.99452;-0.24546;-3.00339;,
 -4.05372;-0.07586;-2.63197;,
 -3.98707;-0.27245;-2.27623;,
 -5.97958;-0.84011;-1.50702;,
 -5.99186;-1.50633;-1.47836;,
 -5.94721;-1.97871;-1.66194;,
 -6.14341;-2.23458;-2.06708;,
 -6.46537;-2.12454;-2.45662;,
 -6.72462;-1.71255;-2.60231;,
 -6.76915;-1.24055;-2.41880;,
 -6.57300;-0.98452;-2.01358;,
 -5.97958;-0.84011;-1.50702;,
 -6.27762;-1.15579;0.00610;,
 -6.01992;-1.56204;0.00745;,
 -5.97384;-2.03978;-0.03171;,
 -6.16649;-2.30860;-0.08841;,
 -6.48485;-2.21147;-0.12944;,
 -6.74264;-1.80486;-0.13077;,
 -6.78864;-1.32747;-0.09162;,
 -6.24447;-0.94685;0.32652;,
 -6.27762;-1.15579;0.00610;,
 -2.04453;-0.10089;-2.11075;,
 -2.04678;-0.09287;-2.32665;,
 -2.19618;0.34013;-2.06237;,
 -1.91975;-0.25814;-2.26880;,
 -1.85746;-0.43895;-2.34195;,
 -1.92089;-0.25397;-2.38139;,
 -2.04701;-0.09197;-2.35126;,
 -2.19732;0.34431;-2.17497;,
 -2.25940;0.52431;-2.08394;,
 -6.27762;-1.15579;0.00610;,
 -6.37780;-1.69619;0.28148;,
 -6.01992;-1.56204;0.00745;,
 -5.97384;-2.03978;-0.03171;,
 -6.16649;-2.30860;-0.08841;,
 -6.48485;-2.21147;-0.12944;,
 -6.74264;-1.80486;-0.13077;,
 -6.78864;-1.32747;-0.09162;,
 -6.24447;-0.94685;0.32652;,
 -2.54741;2.29216;-0.45286;,
 -1.93086;2.19516;-0.91148;,
 -2.72194;2.11650;-1.51843;,
 -2.96281;2.29105;-0.77135;,
 -5.36248;2.01447;-2.14677;,
 -3.47698;2.28425;-0.77472;,
 -5.58682;1.98001;-1.06254;,
 -3.89356;2.27438;-0.46167;,
 -5.59948;1.79448;0.03128;,
 -4.05339;2.26516;0.04823;,
 -5.59093;1.94955;1.13037;,
 -3.89548;2.26019;0.56020;,
 -5.37066;1.95381;2.21801;,
 -3.48007;2.26129;0.87869;,
 -2.72783;2.07278;1.62654;,
 -2.96589;2.26806;0.88204;,
 -1.93450;2.16814;1.03222;,
 -2.54931;2.27793;0.56901;,
 -1.63044;2.18563;0.06235;,
 -2.38948;2.28716;0.05911;,
 -1.93086;2.19516;-0.91148;,
 -2.54741;2.29216;-0.45286;,
 -1.43664;1.90866;-1.27858;,
 -2.52415;1.90574;-2.11241;,
 -5.87965;1.79428;-2.13538;,
 -6.07111;1.87701;-1.08301;,
 -6.05085;1.72411;0.02729;,
 -6.07529;1.84613;1.14144;,
 -5.88777;1.73413;2.19330;,
 -2.53223;1.84560;2.21627;,
 -1.44164;1.87147;1.39669;,
 -1.02317;1.89554;0.06179;,
 -1.43664;1.90866;-1.27858;,
 0.60488;1.16562;-0.99322;,
 -2.39532;1.16223;-2.50286;,
 -6.25399;0.99410;-2.19476;,
 -6.36433;1.05314;-1.13234;,
 -6.40356;1.06383;0.01512;,
 -6.36862;1.02125;1.16223;,
 -6.26226;0.93269;2.22382;,
 -2.40486;1.09151;2.58580;,
 0.59559;1.12194;1.08198;,
 1.18083;1.15024;0.04729;,
 0.60488;1.16562;-0.99322;,
 0.72265;0.33638;-1.08589;,
 -2.34334;0.33279;-2.64599;,
 -6.59096;0.23283;-2.23491;,
 -6.69226;0.29003;-1.14347;,
 -6.76144;0.31212;0.00154;,
 -6.69655;0.25820;1.14622;,
 -6.59933;0.17070;2.23675;,
 -2.35337;0.25845;2.70455;,
 -4.38919;0.21638;2.48024;,
 0.71306;0.29042;1.15115;,
 1.32361;0.32021;0.03572;,
 0.72265;0.33638;-1.08589;,
 0.62691;-0.49796;-1.01812;,
 -2.37329;-0.50134;-2.52777;,
 -5.90028;-0.92904;-2.27426;,
 -5.96033;-0.93323;-1.14557;,
 -6.09606;-0.98290;-0.02264;,
 -5.96140;-0.97345;1.10271;,
 -5.90241;-1.00963;2.23137;,
 -4.42925;0.20499;2.42652;,
 -2.38283;-0.57206;2.56090;,
 0.61761;-0.54164;1.05708;,
 1.20286;-0.51334;0.02239;,
 0.62691;-0.49796;-1.01812;,
 -1.39474;-1.25565;-1.32594;,
 -2.47392;-0.60379;-2.14999;,
 -5.15088;-0.54827;-2.23230;,
 -4.89876;-1.17108;-1.09082;,
 -4.98755;-1.24878;-0.02247;,
 -4.89976;-1.20935;1.04901;,
 -4.76393;-1.15448;2.20296;,
 -4.43264;0.18822;2.21050;,
 -2.49036;-1.31870;2.16890;,
 -1.39975;-1.29282;1.34933;,
 -0.98126;-1.26875;0.01442;,
 -1.39474;-1.25565;-1.32594;,
 -1.86940;-0.98563;-0.97223;,
 -2.64421;-0.66357;-1.56008;,
 -5.31609;-0.62742;-2.23689;,
 -4.54261;-0.56657;-1.09040;,
 -4.56010;-0.62248;-0.00842;,
 -4.54365;-0.60530;1.07512;,
 -4.45216;-0.33465;2.23104;,
 -4.42331;0.12557;2.02644;,
 -2.66539;-1.03145;1.56693;,
 -1.87304;-1.01264;0.97147;,
 -1.56899;-0.99516;0.00160;,
 -1.86940;-0.98563;-0.97223;,
 -4.42451;-0.32172;-0.49045;,
 -4.83991;-0.32280;-0.80894;,
 -5.35409;-0.32961;-0.81230;,
 -5.77066;-0.33947;-0.49926;,
 -5.93051;-0.34868;0.01064;,
 -5.77258;-0.35368;0.52261;,
 -5.35719;-0.35258;0.84109;,
 -4.84300;-0.34580;0.84446;,
 -4.42643;-0.33592;0.53143;,
 -4.26659;-0.32672;0.02152;,
 -4.42451;-0.32172;-0.49045;,
 -3.22445;2.30859;0.05416;,
 -3.22445;2.30859;0.05416;,
 -3.22445;2.30859;0.05416;,
 -3.22445;2.30859;0.05416;,
 -3.22445;2.30859;0.05416;,
 -3.22445;2.30859;0.05416;,
 -3.22445;2.30859;0.05416;,
 -3.22445;2.30859;0.05416;,
 -3.22445;2.30859;0.05416;,
 -3.22445;2.30859;0.05416;,
 -5.10755;-0.19594;0.01816;,
 -5.10755;-0.19594;0.01816;,
 -5.10755;-0.19594;0.01816;,
 -5.10755;-0.19594;0.01816;,
 -5.10755;-0.19594;0.01816;,
 -5.10755;-0.19594;0.01816;,
 -5.10755;-0.19594;0.01816;,
 -5.10755;-0.19594;0.01816;,
 -5.10755;-0.19594;0.01816;,
 -5.10755;-0.19594;0.01816;;
 
 155;
 4;0,1,2,3;,
 4;3,2,4,5;,
 4;5,4,6,7;,
 4;7,6,8,9;,
 4;9,8,10,11;,
 4;11,10,12,13;,
 4;13,12,14,15;,
 4;15,14,16,17;,
 4;1,18,19,2;,
 4;2,19,20,4;,
 4;4,20,21,6;,
 4;6,21,22,8;,
 4;8,22,23,10;,
 4;10,23,24,12;,
 4;12,24,25,14;,
 4;14,25,26,16;,
 4;18,27,28,19;,
 4;19,28,29,20;,
 4;20,29,30,21;,
 4;21,30,31,22;,
 4;22,31,32,23;,
 4;23,32,33,24;,
 4;24,33,34,25;,
 4;25,34,35,26;,
 4;27,36,37,28;,
 4;28,37,38,29;,
 4;29,38,39,30;,
 4;30,39,40,31;,
 4;31,40,41,32;,
 4;32,41,42,33;,
 4;33,42,43,34;,
 4;34,43,44,35;,
 3;45,46,47;,
 3;48,46,45;,
 3;49,46,48;,
 3;50,46,49;,
 3;51,46,50;,
 3;52,46,51;,
 3;53,46,52;,
 3;47,46,53;,
 3;54,55,56;,
 3;56,55,57;,
 3;57,55,58;,
 3;58,55,59;,
 3;59,55,60;,
 3;60,55,61;,
 3;61,55,62;,
 3;62,55,54;,
 4;63,64,65,66;,
 4;66,65,67,68;,
 4;68,67,69,70;,
 4;70,69,71,72;,
 4;72,71,73,74;,
 4;74,73,75,76;,
 4;76,75,77,78;,
 4;78,77,79,80;,
 4;80,79,81,82;,
 4;82,81,83,84;,
 4;64,85,86,65;,
 4;65,86,87,67;,
 4;67,87,88,69;,
 4;69,88,89,71;,
 4;71,89,90,73;,
 4;73,90,91,75;,
 4;75,91,92,77;,
 4;77,92,93,79;,
 4;79,93,94,81;,
 4;81,94,95,83;,
 4;85,96,97,86;,
 4;86,97,98,87;,
 4;87,98,99,88;,
 4;88,99,100,89;,
 4;89,100,101,90;,
 4;90,101,102,91;,
 4;91,102,103,92;,
 4;92,103,104,93;,
 4;93,104,105,94;,
 4;94,105,106,95;,
 4;96,107,108,97;,
 4;97,108,109,98;,
 4;98,109,110,99;,
 4;99,110,111,100;,
 4;100,111,112,101;,
 4;101,112,113,102;,
 3;114,103,115;,
 3;103,102,115;,
 3;102,113,115;,
 4;103,114,116,104;,
 4;104,116,117,105;,
 4;105,117,118,106;,
 4;107,119,120,108;,
 4;108,120,121,109;,
 4;109,121,122,110;,
 4;110,122,123,111;,
 4;111,123,124,112;,
 4;112,124,125,113;,
 4;113,125,126,115;,
 4;114,127,128,116;,
 4;116,128,129,117;,
 4;117,129,130,118;,
 4;119,131,132,120;,
 4;120,132,133,121;,
 4;121,133,134,122;,
 4;122,134,135,123;,
 4;123,135,136,124;,
 4;124,136,137,125;,
 4;125,137,138,126;,
 4;127,139,140,128;,
 4;128,140,141,129;,
 4;129,141,142,130;,
 4;131,143,144,132;,
 4;132,144,145,133;,
 4;133,145,146,134;,
 4;134,146,147,135;,
 4;135,147,148,136;,
 4;136,148,149,137;,
 4;137,149,150,138;,
 4;139,151,152,140;,
 4;140,152,153,141;,
 4;141,153,154,142;,
 4;143,155,156,144;,
 4;144,156,157,145;,
 4;145,157,158,146;,
 4;146,158,159,147;,
 4;147,159,160,148;,
 4;148,160,161,149;,
 3;151,150,162;,
 3;150,149,162;,
 3;149,161,162;,
 4;151,162,163,152;,
 4;152,163,164,153;,
 4;153,164,165,154;,
 3;66,166,63;,
 3;68,167,66;,
 3;70,168,68;,
 3;72,169,70;,
 3;74,170,72;,
 3;76,171,74;,
 3;78,172,76;,
 3;80,173,78;,
 3;82,174,80;,
 3;84,175,82;,
 3;155,176,156;,
 3;156,177,157;,
 3;157,178,158;,
 3;158,179,159;,
 3;159,180,160;,
 3;160,181,161;,
 3;161,182,162;,
 3;162,183,163;,
 3;163,184,164;,
 3;164,185,165;,
 4;126,127,114,115;,
 4;138,139,127,126;,
 4;150,151,139,138;;
 
 MeshMaterialList {
  1;
  155;
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
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "data\\TEXTURE\\neet12.jpg";
   }
  }
 }
 MeshNormals {
  188;
  0.061122;0.389604;0.918952;,
  0.383401;-0.270351;0.883127;,
  0.342286;-0.640179;0.687758;,
  0.275032;-0.619089;0.735586;,
  0.513480;-0.115467;-0.850298;,
  0.412161;0.312904;-0.855695;,
  0.248998;0.610530;-0.751833;,
  0.100282;0.740840;-0.664154;,
  -0.160313;0.478435;0.863365;,
  0.105700;-0.234967;0.966239;,
  0.259470;-0.674975;0.690713;,
  0.287596;-0.749325;0.596490;,
  0.375731;-0.356242;-0.855522;,
  0.214025;0.185490;-0.959055;,
  0.024447;0.640625;-0.767464;,
  -0.097395;0.819111;-0.565306;,
  -0.180926;0.618651;0.764550;,
  0.086208;-0.111361;0.990034;,
  0.293539;-0.654822;0.696450;,
  0.331470;-0.942586;-0.040727;,
  0.137466;-0.613059;-0.777986;,
  -0.099437;0.008209;-0.995010;,
  -0.291343;0.623518;-0.725496;,
  -0.332358;0.942850;-0.023917;,
  0.269165;0.195971;0.942945;,
  0.325685;-0.036642;0.944768;,
  0.598598;-0.638982;0.483097;,
  0.329863;-0.943316;-0.036688;,
  -0.308882;-0.834611;-0.456089;,
  -0.191960;-0.024088;-0.981107;,
  -0.532712;0.695755;-0.481812;,
  -0.465618;0.884837;-0.016230;,
  0.886448;0.371813;0.275619;,
  0.853533;0.189143;0.485496;,
  0.821760;-0.274481;0.499370;,
  0.808481;-0.588425;-0.010697;,
  -0.584851;-0.707539;0.396658;,
  -0.878364;-0.316925;0.357819;,
  -0.889897;0.158655;0.427682;,
  -0.770930;0.436853;0.463493;,
  0.898998;0.437330;0.023360;,
  0.329434;-0.188758;0.925118;,
  0.060060;0.996885;-0.051117;,
  0.017176;0.994286;-0.105360;,
  -0.044484;0.996063;-0.076678;,
  -0.111096;0.993809;0.001066;,
  -0.139758;0.990094;0.013488;,
  -0.111255;0.993448;0.026124;,
  -0.045610;0.993511;0.104194;,
  0.015709;0.990982;0.133069;,
  0.059260;0.995106;0.079068;,
  0.079121;0.996766;0.014024;,
  0.213828;0.962999;-0.164043;,
  0.082821;0.908688;-0.409179;,
  -0.107034;0.941387;-0.319896;,
  -0.210024;0.977452;0.021869;,
  -0.205046;0.978663;0.013209;,
  -0.209894;0.977714;0.004515;,
  -0.111223;0.931680;0.345835;,
  0.077614;0.897003;0.435157;,
  0.211767;0.958327;0.191739;,
  0.284595;0.958547;0.013894;,
  0.369548;0.866824;-0.334739;,
  0.171389;0.628498;-0.758693;,
  -0.120579;0.687202;-0.716390;,
  -0.648068;0.761289;-0.021139;,
  -0.623126;0.782062;0.009691;,
  -0.648285;0.760357;0.039803;,
  -0.387783;0.657134;0.646374;,
  0.164037;0.605505;0.778753;,
  0.368892;0.855355;0.363712;,
  0.385855;0.922422;0.015918;,
  0.591311;0.521192;-0.615395;,
  0.197744;0.308147;-0.930561;,
  -0.069966;0.212482;-0.974657;,
  -0.913000;0.400902;-0.075554;,
  -0.913096;0.407725;0.003946;,
  -0.913489;0.398276;0.083156;,
  -0.910885;0.387916;0.140745;,
  0.130360;0.251278;0.959096;,
  0.588886;0.499571;0.635328;,
  0.339679;0.940361;0.018394;,
  0.696341;0.019964;-0.717434;,
  0.190091;0.022897;-0.981499;,
  -0.084025;0.024717;-0.996157;,
  -0.995265;-0.050821;-0.082856;,
  -0.999166;-0.040737;-0.002699;,
  -0.995613;-0.052922;0.077165;,
  -0.994345;-0.064140;0.084641;,
  0.146162;-0.121826;0.981731;,
  0.692518;-0.001606;0.721399;,
  0.999902;0.013176;0.004736;,
  0.550376;-0.576326;-0.604098;,
  0.223197;-0.372336;-0.900860;,
  -0.075182;-0.080866;-0.993885;,
  -0.702614;-0.707345;-0.077438;,
  -0.600680;-0.799359;-0.014448;,
  -0.583413;-0.810907;0.045376;,
  -0.567161;-0.823092;0.029138;,
  0.075682;-0.573194;0.815917;,
  0.596597;-0.509848;0.619780;,
  0.987916;-0.154981;0.001409;,
  -0.065094;-0.979213;-0.192108;,
  -0.014410;-0.898287;-0.439173;,
  0.123300;-0.984597;-0.123957;,
  -0.036949;-0.986852;-0.157345;,
  -0.223750;-0.974489;-0.017546;,
  -0.197612;-0.979729;0.032868;,
  -0.171477;-0.984965;0.020963;,
  -0.208671;-0.844105;0.493906;,
  0.420041;-0.794607;0.438366;,
  -0.041431;-0.999027;-0.015135;,
  -0.313444;-0.949392;0.020216;,
  -0.132336;-0.983506;-0.123298;,
  0.047593;-0.979554;-0.195472;,
  0.404578;0.914323;-0.018171;,
  0.844249;-0.535872;-0.009182;,
  0.874322;-0.484411;-0.030129;,
  0.953054;-0.233269;0.193064;,
  -0.388041;-0.920375;-0.048311;,
  -0.277673;-0.934090;-0.224439;,
  -0.332447;-0.943025;-0.013496;,
  -0.169840;-0.983980;0.054204;,
  -0.076054;-0.989528;0.122679;,
  0.032943;-0.985527;0.166290;,
  0.270617;0.953354;0.133724;,
  0.201917;0.979273;0.015965;,
  0.292893;0.932808;-0.209960;,
  0.371906;0.848424;-0.376647;,
  -0.139379;-0.989649;-0.034182;,
  -0.170989;-0.973622;-0.151074;,
  -0.197249;-0.980252;-0.014115;,
  -0.013360;0.999815;0.013872;,
  0.014065;-0.999805;-0.013888;,
  -0.134709;-0.195473;0.971413;,
  -0.061979;-0.665629;0.743705;,
  0.548501;-0.275057;0.789614;,
  0.604222;0.008743;0.796768;,
  0.749379;0.032810;-0.661328;,
  0.435356;-0.626496;-0.646505;,
  -0.162264;0.569173;0.806047;,
  -0.260816;0.721760;0.641122;,
  0.195641;0.967302;0.161403;,
  0.954158;0.274714;0.118805;,
  0.980490;0.183584;0.070262;,
  0.995689;0.090369;0.020920;,
  -0.312466;-0.854286;0.415403;,
  -0.945899;-0.323874;-0.019506;,
  -0.995660;-0.092385;-0.011249;,
  0.549864;0.835199;-0.009593;,
  0.879868;0.475143;0.008481;,
  0.945736;0.324928;0.002267;,
  0.809160;0.545476;-0.218441;,
  0.797283;0.517401;0.310864;,
  0.727201;0.372315;0.576680;,
  0.879952;0.474974;0.009145;,
  0.945844;0.324605;0.003141;,
  0.945801;0.324736;0.002785;,
  0.317015;-0.407796;0.856273;,
  -0.679063;-0.155451;0.717432;,
  0.984321;-0.175914;0.012873;,
  -0.909982;0.384274;-0.155775;,
  -0.910047;0.392434;-0.133457;,
  -0.089469;0.144280;0.985484;,
  -0.993941;-0.062172;-0.090639;,
  -0.089960;-0.315547;0.944636;,
  0.983464;0.180932;0.007927;,
  -0.858149;-0.510946;-0.050140;,
  0.202327;-0.613881;0.763030;,
  0.064767;-0.880853;0.468938;,
  0.115159;-0.984996;0.128532;,
  0.150665;-0.961818;-0.228489;,
  0.742284;-0.364499;0.562277;,
  0.345684;-0.938227;-0.015268;,
  0.618794;0.718262;-0.318110;,
  0.502959;0.862058;-0.062354;,
  0.844086;-0.536154;0.007646;,
  -0.247456;-0.900444;-0.357723;,
  -0.334213;-0.907540;-0.254309;,
  0.337077;0.920074;0.199606;,
  -0.516059;-0.821525;0.242443;,
  0.947581;-0.177511;-0.265670;,
  0.013156;-0.999904;0.004332;,
  0.048767;-0.992700;-0.110311;,
  0.149472;-0.985378;0.081781;,
  0.182583;-0.983100;-0.013329;,
  0.150703;-0.982598;-0.108579;,
  -0.506962;-0.813870;0.283912;;
  155;
  4;0,8,9,1;,
  4;1,9,10,2;,
  4;2,10,11,3;,
  4;138,139,12,4;,
  4;4,12,13,5;,
  4;5,13,14,6;,
  4;6,14,15,7;,
  4;140,141,8,0;,
  4;8,16,17,9;,
  4;9,17,18,10;,
  4;10,18,19,11;,
  4;139,19,20,12;,
  4;12,20,21,13;,
  4;13,21,22,14;,
  4;14,22,23,15;,
  4;141,23,16,8;,
  4;16,24,25,17;,
  4;17,25,26,18;,
  4;18,26,27,19;,
  4;19,27,28,20;,
  4;20,28,29,21;,
  4;21,29,30,22;,
  4;22,30,31,23;,
  4;23,31,142,16;,
  4;143,32,33,144;,
  4;144,33,34,145;,
  4;26,34,35,27;,
  4;27,146,36,28;,
  4;28,36,37,147;,
  4;147,37,38,148;,
  4;30,38,39,31;,
  4;149,149,32,142;,
  3;150,40,151;,
  3;152,40,150;,
  3;138,40,152;,
  3;153,40,154;,
  3;155,40,153;,
  3;156,40,155;,
  3;157,40,156;,
  3;151,40,157;,
  3;32,41,33;,
  3;33,41,34;,
  3;34,41,158;,
  3;146,41,36;,
  3;36,159,37;,
  3;37,159,38;,
  3;38,159,39;,
  3;160,160,32;,
  4;42,52,53,43;,
  4;43,53,54,44;,
  4;44,54,55,45;,
  4;45,55,56,46;,
  4;46,56,57,47;,
  4;47,57,58,48;,
  4;48,58,59,49;,
  4;49,59,60,50;,
  4;50,60,61,51;,
  4;51,61,52,42;,
  4;52,62,63,53;,
  4;53,63,64,54;,
  4;54,64,65,55;,
  4;55,65,66,56;,
  4;56,66,67,57;,
  4;57,67,68,58;,
  4;58,68,69,59;,
  4;59,69,70,60;,
  4;60,70,71,61;,
  4;61,71,62,52;,
  4;62,72,73,63;,
  4;63,73,74,64;,
  4;161,162,75,65;,
  4;65,75,76,66;,
  4;66,76,77,67;,
  4;67,77,78,68;,
  4;68,163,79,69;,
  4;69,79,80,70;,
  4;70,80,81,71;,
  4;71,81,72,62;,
  4;72,82,83,73;,
  4;73,83,84,74;,
  4;162,164,85,75;,
  4;75,85,86,76;,
  4;76,86,87,77;,
  4;77,87,88,78;,
  3;89,79,134;,
  3;79,163,134;,
  3;163,165,134;,
  4;79,89,90,80;,
  4;80,90,91,166;,
  4;166,91,82,72;,
  4;82,92,93,83;,
  4;83,93,94,84;,
  4;164,167,95,85;,
  4;85,95,96,86;,
  4;86,96,97,87;,
  4;87,97,98,88;,
  4;165,168,135,134;,
  4;89,99,100,90;,
  4;90,100,101,91;,
  4;91,101,92,82;,
  4;92,102,103,93;,
  4;169,169,104,170;,
  4;170,104,105,171;,
  4;95,105,106,96;,
  4;96,106,107,97;,
  4;97,107,108,98;,
  4;168,172,136,135;,
  4;99,109,110,100;,
  4;100,110,111,173;,
  4;173,111,102,92;,
  4;102,112,113,103;,
  4;103,113,114,104;,
  4;174,175,115,174;,
  4;176,176,116,116;,
  4;116,116,117,117;,
  4;117,117,118,172;,
  4;172,118,137,136;,
  4;177,119,120,178;,
  4;178,120,121,111;,
  4;111,121,112,102;,
  4;112,122,123,113;,
  4;113,123,124,114;,
  4;175,179,125,115;,
  4;115,125,126,126;,
  4;126,126,127,127;,
  4;127,127,128,128;,
  3;119,180,129;,
  3;181,118,181;,
  3;182,183,129;,
  4;119,129,130,120;,
  4;120,130,131,121;,
  4;121,131,122,112;,
  3;43,132,42;,
  3;44,132,43;,
  3;45,132,44;,
  3;46,132,45;,
  3;47,132,46;,
  3;48,132,47;,
  3;49,132,48;,
  3;50,132,49;,
  3;51,132,50;,
  3;42,132,51;,
  3;122,133,123;,
  3;123,133,124;,
  3;124,133,184;,
  3;184,133,185;,
  3;185,133,186;,
  3;186,133,183;,
  3;183,133,129;,
  3;129,133,130;,
  3;130,133,131;,
  3;131,133,122;,
  4;135,99,89,134;,
  4;187,109,99,135;,
  4;180,119,109,187;;
 }
 MeshTextureCoords {
  186;
  0.605386;0.269512;,
  0.605386;0.258073;,
  0.609189;0.258073;,
  0.609189;0.269512;,
  0.612993;0.258073;,
  0.612993;0.269512;,
  0.616796;0.258073;,
  0.616796;0.269512;,
  0.620599;0.258073;,
  0.620599;0.269512;,
  0.624402;0.258073;,
  0.624402;0.269512;,
  0.628206;0.258073;,
  0.628206;0.269512;,
  0.632009;0.258073;,
  0.632009;0.269512;,
  0.635812;0.258073;,
  0.635812;0.269512;,
  0.605386;0.246635;,
  0.609189;0.246635;,
  0.612993;0.246635;,
  0.616796;0.246635;,
  0.620599;0.246635;,
  0.624402;0.246635;,
  0.628206;0.246635;,
  0.632009;0.246635;,
  0.635812;0.246635;,
  0.605386;0.235197;,
  0.609189;0.235197;,
  0.612993;0.235197;,
  0.616796;0.235197;,
  0.620599;0.235197;,
  0.624402;0.235197;,
  0.628206;0.235197;,
  0.632009;0.235197;,
  0.635812;0.235197;,
  0.605386;0.223758;,
  0.609189;0.223758;,
  0.612993;0.223758;,
  0.616796;0.223758;,
  0.620599;0.223758;,
  0.624402;0.223758;,
  0.628206;0.223758;,
  0.632009;0.223758;,
  0.635812;0.223758;,
  0.620599;0.307544;,
  0.620599;0.289288;,
  0.634045;0.301974;,
  0.607153;0.301974;,
  0.601583;0.288528;,
  0.607153;0.275081;,
  0.620599;0.269512;,
  0.634045;0.275081;,
  0.639615;0.288528;,
  0.634045;0.191410;,
  0.620599;0.205617;,
  0.620599;0.185840;,
  0.607153;0.191410;,
  0.601583;0.204856;,
  0.607153;0.218303;,
  0.620599;0.223873;,
  0.634045;0.218303;,
  0.639615;0.204856;,
  0.573079;0.293826;,
  0.573079;0.281656;,
  0.585250;0.281656;,
  0.585250;0.293826;,
  0.597420;0.281656;,
  0.597420;0.293826;,
  0.609590;0.281656;,
  0.609590;0.293826;,
  0.621761;0.281656;,
  0.621761;0.293826;,
  0.633931;0.281656;,
  0.633931;0.293826;,
  0.646102;0.281656;,
  0.646102;0.293826;,
  0.658272;0.281656;,
  0.658272;0.293826;,
  0.670442;0.281656;,
  0.670442;0.293826;,
  0.682613;0.281656;,
  0.682613;0.293826;,
  0.694783;0.281656;,
  0.694783;0.293826;,
  0.573079;0.269485;,
  0.585250;0.269485;,
  0.597420;0.269485;,
  0.609590;0.269485;,
  0.621761;0.269485;,
  0.633931;0.269485;,
  0.646102;0.269485;,
  0.658272;0.269485;,
  0.670442;0.269485;,
  0.682613;0.269485;,
  0.694783;0.269485;,
  0.573079;0.257315;,
  0.585250;0.257315;,
  0.597420;0.257315;,
  0.609590;0.257315;,
  0.621761;0.257315;,
  0.633931;0.257315;,
  0.646102;0.257315;,
  0.658272;0.257315;,
  0.670442;0.257315;,
  0.682613;0.257315;,
  0.694783;0.257315;,
  0.573079;0.245145;,
  0.585250;0.245145;,
  0.597420;0.245145;,
  0.609590;0.245145;,
  0.621761;0.245145;,
  0.633931;0.245145;,
  0.646102;0.245145;,
  0.658272;0.245145;,
  0.652437;0.245145;,
  0.670442;0.245145;,
  0.682613;0.245145;,
  0.694783;0.245145;,
  0.573079;0.232974;,
  0.585250;0.232974;,
  0.597420;0.232974;,
  0.609590;0.232974;,
  0.621761;0.232974;,
  0.633931;0.232974;,
  0.646102;0.232974;,
  0.652720;0.232974;,
  0.658272;0.232974;,
  0.670442;0.232974;,
  0.682613;0.232974;,
  0.694783;0.232974;,
  0.573079;0.220804;,
  0.585250;0.220804;,
  0.597420;0.220804;,
  0.609590;0.220804;,
  0.621761;0.220804;,
  0.633931;0.220804;,
  0.646102;0.220804;,
  0.651604;0.220804;,
  0.658272;0.220804;,
  0.670442;0.220804;,
  0.682613;0.220804;,
  0.694783;0.220804;,
  0.573079;0.208633;,
  0.585250;0.208633;,
  0.597420;0.208633;,
  0.609590;0.208633;,
  0.621761;0.208633;,
  0.633931;0.208633;,
  0.646102;0.208633;,
  0.650155;0.208633;,
  0.658272;0.208633;,
  0.670442;0.208633;,
  0.682613;0.208633;,
  0.694783;0.208633;,
  0.573079;0.196463;,
  0.585250;0.196463;,
  0.597420;0.196463;,
  0.609590;0.196463;,
  0.621761;0.196463;,
  0.633931;0.196463;,
  0.646102;0.196463;,
  0.658272;0.196463;,
  0.670442;0.196463;,
  0.682613;0.196463;,
  0.694783;0.196463;,
  0.579164;0.305996;,
  0.591335;0.305996;,
  0.603505;0.305996;,
  0.615676;0.305996;,
  0.627846;0.305996;,
  0.640016;0.305996;,
  0.652187;0.305996;,
  0.664357;0.305996;,
  0.676527;0.305996;,
  0.688698;0.305996;,
  0.579164;0.184293;,
  0.591335;0.184293;,
  0.603505;0.184293;,
  0.615676;0.184293;,
  0.627846;0.184293;,
  0.640016;0.184293;,
  0.652187;0.184293;,
  0.664357;0.184293;,
  0.676527;0.184293;,
  0.688698;0.184293;;
 }
}
