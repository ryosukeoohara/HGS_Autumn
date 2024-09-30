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
 291;
 17.20980;-0.35245;4.80975;,
 6.47215;-0.35245;6.21855;,
 6.47215;4.04475;4.39710;,
 17.20980;3.04855;3.40100;,
 17.20980;-3.75345;3.40100;,
 6.47215;-4.74955;4.39710;,
 17.20980;-5.16225;-0.00000;,
 6.47215;-6.57095;-0.00000;,
 17.20980;-3.75345;-3.40100;,
 6.47215;-4.74955;-4.39710;,
 17.20980;-0.35245;-4.80975;,
 6.47215;-0.35245;-6.21855;,
 17.20980;3.04855;-3.40100;,
 6.47215;4.04475;-4.39710;,
 17.20980;4.45735;0.00000;,
 6.47215;5.86610;0.00000;,
 0.00000;-0.35245;-0.00000;,
 0.00000;-0.35245;10.15140;,
 6.47215;-0.35245;13.02055;,
 6.47215;8.85445;9.20690;,
 0.00000;6.82570;7.17810;,
 0.00000;-7.53060;7.17810;,
 6.47215;-9.55935;9.20690;,
 0.00000;-10.50380;-0.00000;,
 6.47215;-13.37300;-0.00000;,
 0.00000;-7.53060;-7.17810;,
 6.47215;-9.55935;-9.20690;,
 0.00000;-0.35245;-10.15140;,
 6.47215;-0.35245;-13.02055;,
 0.00000;6.82570;-7.17810;,
 6.47215;8.85445;-9.20690;,
 0.00000;9.79895;0.00000;,
 6.47215;12.66815;0.00000;,
 17.20980;-0.35245;14.42930;,
 17.20980;9.85060;10.20310;,
 17.20980;-10.55550;10.20310;,
 17.20980;-14.78175;-0.00000;,
 17.20980;-10.55550;-10.20310;,
 17.20980;-0.35245;-14.42930;,
 17.20980;9.85060;-10.20310;,
 17.20980;14.07690;0.00000;,
 29.38535;-0.35245;13.02055;,
 29.38535;8.85445;9.20690;,
 29.38535;-9.55935;9.20690;,
 29.38535;-13.37300;-0.00000;,
 29.38535;-9.55935;-9.20690;,
 29.38535;-0.35245;-13.02055;,
 29.38535;8.85445;-9.20690;,
 29.38535;12.66815;0.00000;,
 37.05725;-0.35245;9.61945;,
 37.05725;6.44965;6.80210;,
 37.05725;-7.15450;6.80210;,
 37.05725;-9.97195;-0.00000;,
 37.05725;-7.15450;-6.80210;,
 37.05725;-0.35245;-9.61945;,
 37.05725;6.44965;-6.80210;,
 37.05725;9.26705;0.00000;,
 29.38535;-0.35245;6.21855;,
 29.38535;4.04475;4.39710;,
 29.38535;-4.74955;4.39710;,
 29.38535;-6.57095;-0.00000;,
 29.38535;-4.74955;-4.39710;,
 29.38535;-0.35245;-6.21855;,
 29.38535;4.04475;-4.39710;,
 29.38535;5.86610;0.00000;,
 -4.71805;-0.35245;0.00000;,
 -2.21990;4.27395;4.62635;,
 -2.21990;6.19030;0.00000;,
 -2.21990;4.27395;-4.62635;,
 -2.21990;-0.35245;-6.54260;,
 -2.21990;-4.97880;-4.62635;,
 -2.21990;-6.89500;0.00000;,
 -2.21990;-4.97880;4.62635;,
 -2.21990;-0.35245;6.54260;,
 50.15455;17.49560;-3.66650;,
 54.11495;17.47295;-6.42615;,
 52.14740;16.16405;-13.27855;,
 44.53685;16.76145;-8.02385;,
 58.91925;17.43565;-6.02955;,
 76.15360;15.46535;-17.45230;,
 62.79931;17.35705;-2.77310;,
 78.03675;15.32600;-7.14555;,
 64.16585;17.26945;1.56095;,
 77.73365;14.04820;2.06425;,
 62.44400;17.25885;5.76810;,
 77.26895;15.11390;11.31155;,
 58.30685;17.26665;8.69260;,
 74.53630;15.01830;21.42740;,
 53.48600;17.29915;8.69025;,
 50.95840;15.83530;15.30275;,
 49.76860;17.38870;5.61330;,
 43.80965;16.56045;9.45875;,
 48.47125;17.46860;0.91185;,
 41.28940;16.68295;0.59785;,
 50.35130;14.08445;-19.43030;,
 39.42295;14.26230;-11.99290;,
 81.72600;13.43515;-17.64845;,
 83.47600;14.16495;-7.18340;,
 82.85360;13.13080;2.25940;,
 82.68825;13.94755;11.75610;,
 80.07630;12.97940;22.00760;,
 48.66070;13.61735;21.20175;,
 38.38780;13.97605;12.89250;,
 34.83675;14.14160;0.28095;,
 49.23890;8.20370;-23.26575;,
 36.19110;8.33275;-14.58390;,
 85.49485;7.23970;-18.32575;,
 86.79296;7.73335;-7.61245;,
 86.70935;7.81810;2.31945;,
 85.96801;7.50535;12.21655;,
 83.78560;6.76730;22.76180;,
 47.24325;7.65235;24.70835;,
 34.96120;7.99285;14.98165;,
 30.77275;8.21150;0.00000;,
 48.81320;1.98490;-24.59215;,
 35.08075;1.98920;-15.50740;,
 88.90040;1.14510;-18.31335;,
 89.91220;1.54325;-7.58115;,
 90.10310;1.72535;2.34555;,
 89.08911;1.31610;12.20990;,
 87.18415;0.67635;22.80975;,
 46.73515;1.34095;25.76390;,
 65.74160;1.03420;24.84425;,
 33.78795;1.63185;15.57045;,
 29.38535;1.86205;-0.17750;,
 48.89135;-4.90420;-23.14200;,
 36.06990;-4.51925;-14.84715;,
 81.70280;-8.20715;-16.71380;,
 83.10680;-7.83595;-7.88105;,
 83.90225;-8.15285;1.82500;,
 82.27640;-8.11900;11.43565;,
 80.22455;-7.95965;22.13155;,
 66.39400;0.37900;24.12350;,
 34.75920;-4.73255;14.73310;,
 47.25815;-5.12255;24.40660;,
 30.57085;-4.51375;-0.24845;,
 50.14700;-6.50340;-18.59330;,
 39.36125;-10.47680;-12.74535;,
 73.91825;-6.06560;-16.96525;,
 80.66990;-6.76810;-17.35180;,
 80.78440;-6.79845;-7.79330;,
 71.39801;-8.43995;-7.77835;,
 74.04145;-4.14385;-17.31175;,
 81.56890;-7.14215;1.74810;,
 71.78860;-8.97680;1.28245;,
 79.96675;-7.07860;11.19650;,
 70.61970;-8.70650;10.29555;,
 79.03106;-7.32950;20.70440;,
 68.99655;-8.32975;19.98505;,
 65.95855;1.04285;21.73600;,
 66.06810;0.92755;19.91285;,
 37.78140;-10.48260;12.55050;,
 48.74330;-10.81035;20.77975;,
 34.21505;-10.29645;-0.20600;,
 52.32720;-6.76905;-13.81870;,
 44.73575;-15.20460;-8.85475;,
 75.16900;-4.69870;-17.73935;,
 68.25430;-4.27220;-7.92300;,
 75.50090;-4.68930;-17.28115;,
 68.01065;-4.65910;1.22275;,
 67.46670;-4.54210;10.36795;,
 66.23370;-2.67775;20.09320;,
 66.05346;0.49580;18.35425;,
 43.44970;-15.43925;8.69265;,
 51.16720;-15.54675;14.26835;,
 40.94045;-15.30105;-0.02025;,
 71.05925;-4.65950;-5.15615;,
 67.90625;-4.53960;-3.15550;,
 74.46295;-4.55570;-4.58920;,
 67.65130;-2.24435;-7.99360;,
 76.32531;-2.64865;-1.58710;,
 67.46355;-2.61560;1.24540;,
 77.41855;-2.78045;1.86300;,
 66.73640;-2.59415;9.89430;,
 76.14120;-2.78270;4.97545;,
 66.28965;-2.60550;20.25000;,
 73.33795;-3.96830;7.00630;,
 70.91665;-4.76425;8.58070;,
 67.18915;-0.98570;19.80295;,
 67.49411;-4.57615;4.98370;,
 66.38105;-4.56815;1.35575;,
 54.19205;15.42805;-5.88540;,
 50.40970;15.43475;-3.37010;,
 56.19700;15.54840;1.19710;,
 58.73005;15.38190;-5.69755;,
 62.29055;15.31405;-2.87810;,
 63.51325;15.25005;1.49570;,
 61.93160;15.21485;5.75345;,
 58.14905;15.22160;8.26875;,
 53.61090;15.26750;8.08085;,
 50.05060;15.33545;5.26150;,
 48.82785;15.39945;0.88765;,
 72.79306;-3.80725;1.63790;,
 67.07810;-0.26830;21.83940;,
 54.19205;15.42805;-5.88540;,
 50.40970;15.43475;-3.37010;,
 58.73005;15.38190;-5.69755;,
 62.29055;15.31405;-2.87810;,
 63.51325;15.25005;1.49570;,
 61.93160;15.21485;5.75345;,
 58.14905;15.22160;8.26875;,
 53.61090;15.26750;8.08085;,
 50.05060;15.33545;5.26150;,
 48.82785;15.39945;0.88765;,
 80.66990;-6.76810;-17.35180;,
 80.78440;-6.79845;-7.79330;,
 81.56890;-7.14215;1.74810;,
 79.96675;-7.07860;11.19650;,
 79.03106;-7.32950;20.70440;,
 65.95855;1.04285;21.73600;,
 74.04145;-4.14385;-17.31175;,
 75.50090;-4.68930;-17.28115;,
 68.25430;-4.27220;-7.92300;,
 68.01065;-4.65910;1.22275;,
 67.46355;-2.61560;1.24540;,
 67.65130;-2.24435;-7.99360;,
 68.25430;-4.27220;-7.92300;,
 67.46670;-4.54210;10.36795;,
 66.73640;-2.59415;9.89430;,
 66.23370;-2.67775;20.09320;,
 67.46670;-4.54210;10.36795;,
 66.05346;0.49580;18.35425;,
 66.06810;0.92755;19.91285;,
 46.23200;3.18150;-15.69245;,
 44.40250;-1.03565;-16.07300;,
 51.75965;-3.22030;-11.96380;,
 54.14165;1.41400;-13.24475;,
 42.92590;-2.28720;-18.60100;,
 55.61045;-8.44675;-16.99730;,
 43.09180;-4.79330;-19.66950;,
 54.67355;-10.02530;-22.25430;,
 43.05550;-1.85360;-20.63330;,
 55.70900;-7.64765;-27.24620;,
 44.83845;-0.08580;-21.14505;,
 57.55065;-3.40955;-28.61215;,
 46.19750;3.26045;-19.29785;,
 59.30390;0.59805;-26.58775;,
 48.48535;5.36645;-17.22080;,
 60.34015;2.45870;-21.62415;,
 62.08310;-5.57815;-14.48685;,
 64.29410;-0.83835;-16.21015;,
 60.30370;-9.71560;-16.82380;,
 59.90435;-11.45150;-22.01385;,
 61.22960;-9.35735;-26.90240;,
 63.26020;-5.01740;-28.45345;,
 64.99495;-0.76490;-26.26450;,
 65.48300;1.09180;-21.29740;,
 80.27450;-10.82000;-8.15115;,
 80.99981;-4.97290;-9.23320;,
 79.79890;-15.10985;-10.46780;,
 81.96470;-17.49560;-15.64120;,
 85.66015;-16.21245;-20.56295;,
 88.67450;-12.18410;-22.24135;,
 89.38895;-7.72505;-19.93075;,
 87.37400;-5.27170;-15.03530;,
 81.11135;-6.12665;-10.83375;,
 81.21060;-10.72015;-10.58830;,
 80.91140;-11.10600;1.97275;,
 83.18510;-8.30470;2.07100;,
 80.88500;-13.97695;-12.15880;,
 80.52025;-14.40010;1.62145;,
 82.76570;-15.74035;-15.49885;,
 82.24135;-16.25320;1.22290;,
 85.74975;-14.98075;-18.65325;,
 85.06540;-15.58300;1.01060;,
 88.09005;-12.13955;-19.77360;,
 87.33970;-12.77910;1.10890;,
 88.41455;-8.88525;-18.20375;,
 87.73010;-9.48755;1.46005;,
 86.53415;-7.12085;-14.86300;,
 82.77424;-6.86455;4.76380;,
 81.11135;-6.12665;-10.83375;,
 83.18510;-8.30470;2.07100;,
 44.33885;-0.01035;-19.48910;,
 83.18510;-8.30470;2.07100;,
 80.91140;-11.10600;1.97275;,
 83.96865;-12.03095;4.43765;,
 80.52025;-14.40010;1.62145;,
 82.24135;-16.25320;1.22290;,
 85.06540;-15.58300;1.01060;,
 87.33970;-12.77910;1.10890;,
 87.73010;-9.48755;1.46005;,
 82.77424;-6.86455;4.76380;,
 81.11135;-6.12665;-10.83375;,
 81.21060;-10.72015;-10.58830;,
 80.88500;-13.97695;-12.15880;,
 82.76570;-15.74035;-15.49885;,
 85.74975;-14.98075;-18.65325;,
 88.09005;-12.13955;-19.77360;,
 88.41455;-8.88525;-18.20375;,
 86.53415;-7.12085;-14.86300;;
 
 267;
 4;0,1,2,3;,
 4;4,5,1,0;,
 4;6,7,5,4;,
 4;8,9,7,6;,
 4;10,11,9,8;,
 4;12,13,11,10;,
 4;14,15,13,12;,
 4;3,2,15,14;,
 3;1,16,2;,
 3;5,16,1;,
 3;7,16,5;,
 3;9,16,7;,
 3;11,16,9;,
 3;13,16,11;,
 3;15,16,13;,
 3;2,16,15;,
 4;17,18,19,20;,
 4;21,22,18,17;,
 4;23,24,22,21;,
 4;25,26,24,23;,
 4;27,28,26,25;,
 4;29,30,28,27;,
 4;31,32,30,29;,
 4;20,19,32,31;,
 4;18,33,34,19;,
 4;22,35,33,18;,
 4;24,36,35,22;,
 4;26,37,36,24;,
 4;28,38,37,26;,
 4;30,39,38,28;,
 4;32,40,39,30;,
 4;19,34,40,32;,
 4;33,41,42,34;,
 4;35,43,41,33;,
 4;36,44,43,35;,
 4;37,45,44,36;,
 4;38,46,45,37;,
 4;39,47,46,38;,
 4;40,48,47,39;,
 4;34,42,48,40;,
 4;41,49,50,42;,
 4;43,51,49,41;,
 4;44,52,51,43;,
 4;45,53,52,44;,
 4;46,54,53,45;,
 4;47,55,54,46;,
 4;48,56,55,47;,
 4;42,50,56,48;,
 4;49,57,58,50;,
 4;51,59,57,49;,
 4;52,60,59,51;,
 4;53,61,60,52;,
 4;54,62,61,53;,
 4;55,63,62,54;,
 4;56,64,63,55;,
 4;50,58,64,56;,
 4;57,0,3,58;,
 4;59,4,0,57;,
 4;60,6,4,59;,
 4;61,8,6,60;,
 4;62,10,8,61;,
 4;63,12,10,62;,
 4;64,14,12,63;,
 4;58,3,14,64;,
 3;65,66,67;,
 3;65,67,68;,
 3;65,68,69;,
 3;65,69,70;,
 3;65,70,71;,
 3;65,71,72;,
 3;65,72,73;,
 3;65,73,66;,
 4;31,67,66,20;,
 4;29,68,67,31;,
 4;27,69,68,29;,
 4;25,70,69,27;,
 4;23,71,70,25;,
 4;21,72,71,23;,
 4;17,73,72,21;,
 4;20,66,73,17;,
 4;74,75,76,77;,
 4;75,78,79,76;,
 4;78,80,81,79;,
 4;80,82,83,81;,
 4;82,84,85,83;,
 4;84,86,87,85;,
 4;86,88,89,87;,
 4;88,90,91,89;,
 4;90,92,93,91;,
 4;92,74,77,93;,
 4;77,76,94,95;,
 4;76,79,96,94;,
 4;79,81,97,96;,
 4;81,83,98,97;,
 4;83,85,99,98;,
 4;85,87,100,99;,
 4;87,89,101,100;,
 4;89,91,102,101;,
 4;91,93,103,102;,
 4;93,77,95,103;,
 4;95,94,104,105;,
 4;94,96,106,104;,
 4;96,97,107,106;,
 4;97,98,108,107;,
 4;98,99,109,108;,
 4;99,100,110,109;,
 4;100,101,111,110;,
 4;101,102,112,111;,
 4;102,103,113,112;,
 4;103,95,105,113;,
 4;105,104,114,115;,
 4;104,106,116,114;,
 4;106,107,117,116;,
 4;107,108,118,117;,
 4;108,109,119,118;,
 4;109,110,120,119;,
 3;121,122,111;,
 3;111,122,110;,
 3;110,122,120;,
 4;111,112,123,121;,
 4;112,113,124,123;,
 4;113,105,115,124;,
 4;115,114,125,126;,
 4;114,116,127,125;,
 4;116,117,128,127;,
 4;117,118,129,128;,
 4;118,119,130,129;,
 4;119,120,131,130;,
 4;120,122,132,131;,
 4;121,123,133,134;,
 4;123,124,135,133;,
 4;124,115,126,135;,
 4;126,125,136,137;,
 4;125,127,138,136;,
 4;139,140,141,142;,
 4;140,143,144,141;,
 4;143,145,146,144;,
 4;145,147,148,146;,
 4;147,149,150,148;,
 4;134,133,151,152;,
 4;133,135,153,151;,
 4;135,126,137,153;,
 4;137,136,154,155;,
 4;136,138,156,154;,
 4;142,141,157,158;,
 4;141,144,159,157;,
 4;144,146,160,159;,
 4;146,148,161,160;,
 4;148,150,162,161;,
 4;152,151,163,164;,
 4;151,153,165,163;,
 4;153,137,155,165;,
 4;155,154,166,167;,
 4;154,156,168,166;,
 4;156,169,170,168;,
 4;169,171,172,170;,
 4;171,173,174,172;,
 4;173,175,176,174;,
 3;164,177,178;,
 3;176,175,177;,
 3;177,175,178;,
 4;164,163,179,177;,
 4;163,165,180,179;,
 4;165,155,167,180;,
 3;181,182,183;,
 3;184,181,183;,
 3;185,184,183;,
 3;186,185,183;,
 3;187,186,183;,
 3;188,187,183;,
 3;189,188,183;,
 3;190,189,183;,
 3;191,190,183;,
 3;182,191,183;,
 3;167,166,192;,
 3;166,168,192;,
 3;168,170,192;,
 3;170,172,192;,
 3;172,174,192;,
 3;174,176,192;,
 3;176,177,192;,
 3;177,179,192;,
 3;179,180,192;,
 3;180,167,192;,
 4;132,122,121,134;,
 4;193,132,134,152;,
 4;178,193,152,164;,
 4;194,75,74,195;,
 4;196,78,75,194;,
 4;197,80,78,196;,
 4;198,82,80,197;,
 4;199,84,82,198;,
 4;200,86,84,199;,
 4;201,88,86,200;,
 4;202,90,88,201;,
 4;203,92,90,202;,
 4;195,74,92,203;,
 4;204,127,128,205;,
 4;205,128,129,206;,
 4;206,129,130,207;,
 4;207,130,131,208;,
 4;208,131,132,209;,
 4;210,138,127,204;,
 4;211,156,138,210;,
 4;212,169,156,211;,
 4;213,214,215,216;,
 4;217,218,214,213;,
 4;219,175,173,220;,
 4;221,178,175,219;,
 4;209,132,193,222;,
 4;222,193,178,221;,
 4;223,224,225,226;,
 4;224,227,228,225;,
 4;227,229,230,228;,
 4;229,231,232,230;,
 4;231,233,234,232;,
 4;233,235,236,234;,
 4;235,237,238,236;,
 4;237,223,226,238;,
 4;226,225,239,240;,
 4;225,228,241,239;,
 4;228,230,242,241;,
 4;230,232,243,242;,
 4;232,234,244,243;,
 4;234,236,245,244;,
 4;236,238,246,245;,
 4;238,226,240,246;,
 4;240,239,247,248;,
 4;239,241,249,247;,
 4;241,242,250,249;,
 4;242,243,251,250;,
 4;243,244,252,251;,
 4;244,245,253,252;,
 4;245,246,254,253;,
 4;246,240,248,254;,
 4;255,256,257,258;,
 4;256,259,260,257;,
 4;259,261,262,260;,
 4;261,263,264,262;,
 4;263,265,266,264;,
 4;265,267,268,266;,
 4;267,269,270,268;,
 4;269,271,272,270;,
 3;224,223,273;,
 3;227,224,273;,
 3;229,227,273;,
 3;231,229,273;,
 3;233,231,273;,
 3;235,233,273;,
 3;237,235,273;,
 3;223,237,273;,
 3;274,275,276;,
 3;275,277,276;,
 3;277,278,276;,
 3;278,279,276;,
 3;279,280,276;,
 3;280,281,276;,
 3;281,282,276;,
 3;282,274,276;,
 4;283,248,247,284;,
 4;284,247,249,285;,
 4;285,249,250,286;,
 4;286,250,251,287;,
 4;287,251,252,288;,
 4;288,252,253,289;,
 4;289,253,254,290;,
 4;290,254,248,283;;
 
 MeshMaterialList {
  1;
  267;
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
    "tyuuni_suit.png";
   }
  }
 }
 MeshNormals {
  318;
  -0.007647;-0.707086;-0.707086;,
  -0.007647;0.000002;-0.999971;,
  -0.007647;0.707086;-0.707087;,
  -0.007647;0.999971;0.000000;,
  -0.007647;0.707086;0.707087;,
  -0.007647;0.000002;0.999971;,
  -0.007647;-0.707086;0.707086;,
  -0.007647;-0.999971;0.000000;,
  0.320197;-0.669880;-0.669877;,
  0.320199;0.000003;-0.947350;,
  0.320196;0.669880;-0.669877;,
  0.320200;0.947350;0.000000;,
  0.320196;0.669880;0.669877;,
  0.320199;0.000003;0.947350;,
  0.320197;-0.669880;0.669877;,
  0.320199;-0.947350;-0.000000;,
  0.740868;0.257031;-0.620523;,
  -0.271213;0.680603;0.680605;,
  -0.271214;0.000000;0.962519;,
  -0.271214;-0.680604;0.680603;,
  -0.271214;-0.962519;0.000000;,
  -0.271214;-0.680604;-0.680603;,
  -0.271214;0.000000;-0.962519;,
  -0.271213;0.680603;-0.680605;,
  -0.271214;0.962519;0.000000;,
  -0.007647;0.707084;0.707088;,
  -0.007647;0.000000;0.999971;,
  -0.007647;-0.707086;0.707087;,
  -0.007647;-0.999971;0.000000;,
  -0.007647;-0.707086;-0.707087;,
  -0.007647;0.000000;-0.999971;,
  -0.007647;0.707084;-0.707088;,
  -0.007648;0.999971;0.000000;,
  0.263921;0.682034;0.682038;,
  0.263921;-0.000000;0.964544;,
  0.263922;-0.682035;0.682037;,
  0.263921;-0.964544;-0.000000;,
  0.263922;-0.682035;-0.682037;,
  0.263921;-0.000000;-0.964544;,
  0.263921;0.682034;-0.682038;,
  0.263921;0.964544;0.000000;,
  0.405269;0.646434;0.646437;,
  0.405267;-0.000001;0.914198;,
  0.405269;-0.646434;0.646437;,
  0.405268;-0.914198;-0.000000;,
  0.405269;-0.646434;-0.646437;,
  0.405267;-0.000001;-0.914198;,
  0.405269;0.646434;-0.646437;,
  0.405267;0.914198;0.000000;,
  0.263922;-0.682036;-0.682035;,
  0.263923;0.000002;-0.964544;,
  0.263922;0.682035;-0.682036;,
  0.263922;0.964544;0.000000;,
  0.263922;0.682035;0.682036;,
  0.263923;0.000002;0.964544;,
  0.263922;-0.682036;0.682035;,
  0.263923;-0.964544;-0.000000;,
  -0.663225;0.529213;0.529213;,
  -0.663224;0.748421;0.000000;,
  -0.663225;0.529213;-0.529213;,
  -0.663228;-0.000000;-0.748418;,
  -0.663229;-0.529212;-0.529209;,
  -0.663228;-0.748418;0.000000;,
  -0.663229;-0.529212;0.529209;,
  -0.663227;-0.000000;0.748418;,
  -1.000000;-0.000003;-0.000000;,
  -0.897142;0.441743;0.000000;,
  -0.897142;0.312357;0.312361;,
  -0.897142;0.312357;-0.312361;,
  -0.897142;-0.000001;-0.441742;,
  -0.897143;-0.312358;-0.312355;,
  -0.897141;-0.441743;0.000000;,
  -0.897143;-0.312358;0.312355;,
  -0.897142;-0.000001;0.441742;,
  -0.389430;-0.918253;-0.071802;,
  -0.255550;-0.965441;-0.051171;,
  -0.117387;-0.992891;-0.019672;,
  -0.129341;-0.991477;-0.015609;,
  -0.337150;-0.925972;0.170020;,
  -0.110138;-0.974830;-0.193847;,
  -0.261860;-0.959559;-0.103326;,
  0.177078;-0.984173;-0.006917;,
  0.154297;-0.987453;0.033588;,
  -0.458209;-0.849180;0.262560;,
  -0.379083;0.644089;-0.664414;,
  -0.653983;0.645637;-0.394283;,
  -0.881575;-0.469689;-0.047085;,
  -0.938139;-0.340350;-0.063695;,
  -0.980317;-0.187235;-0.062629;,
  -0.514012;-0.780447;0.355942;,
  -0.558234;-0.304425;0.771816;,
  -0.642184;0.008846;0.766500;,
  -0.014130;0.999876;-0.006976;,
  0.001491;0.999847;-0.017412;,
  0.020280;0.999655;-0.016690;,
  0.035087;0.999372;-0.005005;,
  0.040206;0.999105;0.013155;,
  0.033620;0.998960;0.030815;,
  0.017865;0.998990;0.041234;,
  -0.000950;0.999183;0.040416;,
  -0.015627;0.999465;0.028733;,
  -0.020654;0.999730;0.010643;,
  0.009723;0.999882;0.011897;,
  -0.079028;0.993399;-0.083149;,
  -0.173614;0.972851;-0.153031;,
  -0.049998;0.934373;-0.352770;,
  -0.020000;0.987157;-0.158498;,
  0.107114;0.956899;-0.269948;,
  0.056293;0.992333;-0.110027;,
  0.185991;0.982351;0.019843;,
  0.138687;0.990259;0.012342;,
  0.186067;0.982351;0.019100;,
  0.177737;0.983899;0.018760;,
  0.186027;0.982373;0.018337;,
  0.138238;0.990154;0.022020;,
  0.083510;0.949721;0.301757;,
  0.046032;0.989447;0.137386;,
  -0.080455;0.925113;0.371070;,
  -0.034129;0.983193;0.179351;,
  -0.186944;0.969115;0.160833;,
  -0.086382;0.991315;0.099165;,
  -0.238082;0.971244;0.001277;,
  -0.108005;0.994127;0.006858;,
  -0.475049;0.793203;-0.380997;,
  -0.138349;0.684050;-0.716195;,
  0.370366;0.743648;-0.556612;,
  0.593205;0.804967;-0.011661;,
  0.572538;0.819202;0.033282;,
  0.589870;0.803571;0.079548;,
  0.323289;0.726122;0.606820;,
  -0.199391;0.661690;0.722779;,
  -0.507893;0.782518;0.360153;,
  -0.618149;0.785888;-0.016475;,
  -0.717317;0.404242;-0.567489;,
  -0.202675;0.342214;-0.917503;,
  0.124386;0.257886;-0.958135;,
  0.870539;0.488938;-0.055692;,
  0.867908;0.494965;0.041779;,
  0.863051;0.485576;0.139137;,
  0.853861;0.473659;0.215799;,
  -0.213417;0.295884;0.931078;,
  -0.764536;0.384851;0.517083;,
  -0.916335;0.399025;-0.033311;,
  -0.782446;0.020881;-0.622369;,
  -0.212443;-0.015312;-0.977054;,
  0.154355;-0.048718;-0.986814;,
  0.881722;0.467603;-0.062556;,
  0.882674;0.468101;0.042061;,
  0.873673;0.463968;0.146387;,
  0.865643;0.460160;0.197267;,
  0.080962;-0.099729;0.991715;,
  -0.289710;-0.081416;0.953645;,
  -0.831668;-0.000543;0.555273;,
  -0.999011;0.015453;-0.041698;,
  -0.691312;-0.444612;-0.569568;,
  -0.238446;-0.425714;-0.872875;,
  0.156149;-0.237262;-0.958814;,
  0.812204;-0.580155;-0.061192;,
  0.827361;-0.560993;0.027571;,
  0.802806;-0.584714;0.116669;,
  0.782922;-0.607899;0.132256;,
  0.171874;-0.535701;0.826731;,
  -0.191381;-0.523762;0.830089;,
  -0.770709;-0.383151;0.509119;,
  -0.927608;-0.370874;-0.044668;,
  -0.391842;-0.796113;-0.461154;,
  -0.064898;-0.939209;-0.337158;,
  0.019530;-0.830137;0.557217;,
  -0.036352;-0.779249;0.625660;,
  -0.600930;-0.695431;0.394029;,
  -0.723665;-0.688847;-0.042417;,
  0.082272;-0.968566;-0.234759;,
  0.183304;-0.950862;-0.249523;,
  0.111272;-0.877715;0.466084;,
  0.270923;-0.921014;0.279881;,
  -0.213731;-0.958223;0.190071;,
  -0.108465;-0.993929;-0.018450;,
  0.207439;-0.978053;0.019520;,
  0.098039;-0.995102;0.012685;,
  0.192381;-0.972721;0.129628;,
  0.247953;0.953835;-0.169466;,
  0.016713;0.999657;0.020147;,
  0.207930;0.943677;0.257369;,
  0.376409;0.789510;0.484758;,
  0.363097;-0.930992;0.037603;,
  0.479029;-0.751528;0.453582;,
  0.233585;-0.955926;-0.177888;,
  0.256542;-0.966531;0.002106;,
  0.193187;-0.980941;0.020830;,
  0.377564;-0.733095;0.565700;,
  -0.795648;0.605571;0.015087;,
  -0.974124;0.223811;0.031474;,
  -0.949336;-0.312312;-0.034961;,
  -0.730069;-0.682081;-0.042025;,
  0.678490;-0.708463;0.194248;,
  0.904688;-0.398932;0.149642;,
  0.965362;0.055353;0.254973;,
  0.624296;0.778300;0.067106;,
  -0.891447;0.390416;0.229993;,
  -0.861560;0.230188;0.452470;,
  -0.822525;-0.324024;0.467397;,
  -0.340807;-0.722884;0.601073;,
  0.500241;-0.770837;0.394423;,
  0.833120;-0.384136;0.397932;,
  0.856985;0.175018;0.484712;,
  0.102367;-0.237544;0.965968;,
  -0.109896;0.561435;0.820191;,
  0.097005;0.593674;0.798838;,
  -0.041679;-0.062459;0.997177;,
  -0.767040;0.447274;0.459995;,
  -0.286687;-0.751061;0.594742;,
  -0.392222;-0.713861;0.580142;,
  -0.311889;-0.929721;0.195816;,
  -0.645831;-0.289370;0.706517;,
  -0.348438;-0.461205;-0.816015;,
  -0.518030;-0.261357;-0.814456;,
  -0.187603;0.189325;-0.963826;,
  -0.641475;0.477181;-0.600673;,
  0.008225;0.728817;-0.684659;,
  -0.437319;0.698695;-0.566196;,
  0.167576;0.968667;-0.183309;,
  -0.429052;0.827301;-0.362612;,
  0.125049;0.676414;0.725829;,
  -0.119759;-0.126271;0.984740;,
  -0.282802;-0.736242;0.614793;,
  -0.261215;-0.963507;-0.058484;,
  -0.083582;-0.676735;-0.731467;,
  0.144366;0.012482;-0.989446;,
  0.285458;0.684847;-0.670446;,
  0.265317;0.964034;-0.015692;,
  -0.064889;0.727186;0.683367;,
  -0.347693;-0.022693;0.937334;,
  -0.392366;-0.680521;0.618821;,
  -0.257832;-0.964905;-0.049800;,
  -0.018050;-0.714849;-0.699046;,
  0.237030;-0.028924;-0.971072;,
  0.359313;0.669220;-0.650414;,
  0.260401;0.965179;-0.024927;,
  -0.871336;0.490671;0.003988;,
  0.740868;0.257031;0.620523;,
  0.692838;-0.721093;-0.000000;,
  0.405272;0.000002;-0.914196;,
  0.405271;-0.646435;-0.646434;,
  0.405275;0.646434;-0.646434;,
  0.405274;0.914195;0.000000;,
  0.405275;0.646434;0.646434;,
  0.405272;0.000002;0.914196;,
  0.405271;-0.646435;0.646434;,
  0.405271;-0.914197;-0.000000;,
  0.867292;0.479713;-0.132963;,
  0.058624;0.193663;0.979315;,
  0.877629;0.465628;-0.113834;,
  0.081836;-0.199409;0.976493;,
  0.795114;-0.601633;-0.076371;,
  0.062794;-0.446192;0.892731;,
  -0.100345;-0.969337;0.224315;,
  -0.382867;-0.911987;0.147287;,
  0.136582;-0.570925;0.809561;,
  -0.774736;-0.630843;-0.042670;,
  -0.804831;-0.581239;-0.120039;,
  -0.814021;-0.577240;-0.064523;,
  0.219734;0.733102;-0.643644;,
  0.455866;0.814328;-0.359242;,
  0.380579;-0.921657;0.075553;,
  0.486489;-0.804115;0.341654;,
  -0.843475;0.357821;-0.400642;,
  -0.935041;0.270595;-0.229076;,
  0.333184;-0.846789;-0.414653;,
  0.363454;-0.929398;0.064189;,
  0.217181;-0.976076;-0.010360;,
  0.282149;-0.959302;0.011439;,
  0.259402;0.220828;0.940184;,
  0.773779;0.192925;0.603362;,
  -0.357578;0.189222;0.914513;,
  -0.809821;0.210770;0.547509;,
  -0.961446;0.272540;-0.036653;,
  -0.760394;0.232139;-0.606559;,
  -0.280013;0.223504;-0.933616;,
  0.335371;0.254936;-0.906936;,
  0.819792;0.213964;-0.531187;,
  0.983922;0.173337;0.043041;,
  -0.521951;-0.852460;0.029670;,
  -0.401424;-0.915377;-0.030709;,
  -0.402187;-0.913353;-0.063501;,
  -0.467784;-0.882241;-0.053194;,
  -0.528576;-0.847839;-0.042141;,
  0.087371;0.320763;0.943121;,
  -0.047874;0.546866;-0.835850;,
  -0.816591;-0.551906;-0.169054;,
  -0.575368;-0.766852;-0.284412;,
  -0.955450;-0.290930;-0.049739;,
  -0.995754;-0.071405;-0.058092;,
  0.903705;0.114734;-0.412496;,
  0.748369;-0.303514;-0.589765;,
  0.759352;0.650251;0.023637;,
  0.810730;0.582474;-0.058669;,
  -0.443618;-0.734872;0.512997;,
  -0.689905;-0.177223;-0.701871;,
  -0.519073;-0.543572;-0.659615;,
  0.132961;0.791017;0.597172;,
  0.521430;-0.814584;0.254093;,
  0.226971;-0.973645;-0.022336;,
  -0.569431;0.820178;-0.055279;,
  -0.849007;0.527983;-0.020530;,
  -0.863589;0.439631;-0.246857;,
  -0.857551;0.475985;0.195051;,
  -0.790889;0.423603;0.441651;,
  0.583052;0.083780;0.808103;,
  -0.974290;-0.223402;-0.029173;,
  0.813286;-0.266883;0.517048;,
  0.938718;-0.154380;0.308179;,
  0.851075;-0.277761;0.445557;,
  0.766147;-0.392086;0.509203;,
  0.803047;-0.276192;0.528046;,
  0.768564;-0.520678;0.371758;,
  0.874732;-0.400744;0.272486;,
  0.886012;-0.235323;0.399508;,
  0.703377;-0.343592;0.622258;;
  267;
  4;1,9,8,0;,
  4;2,10,9,1;,
  4;3,11,10,2;,
  4;4,12,11,3;,
  4;5,13,12,4;,
  4;6,14,13,5;,
  4;7,15,14,6;,
  4;0,8,15,7;,
  3;9,16,8;,
  3;10,16,9;,
  3;11,16,10;,
  3;12,239,11;,
  3;13,239,12;,
  3;14,239,13;,
  3;15,240,14;,
  3;8,240,15;,
  4;64,18,17,57;,
  4;63,19,18,64;,
  4;62,20,19,63;,
  4;61,21,20,62;,
  4;60,22,21,61;,
  4;59,23,22,60;,
  4;58,24,23,59;,
  4;57,17,24,58;,
  4;18,26,25,17;,
  4;19,27,26,18;,
  4;20,28,27,19;,
  4;21,29,28,20;,
  4;22,30,29,21;,
  4;23,31,30,22;,
  4;24,32,31,23;,
  4;17,25,32,24;,
  4;26,34,33,25;,
  4;27,35,34,26;,
  4;28,36,35,27;,
  4;29,37,36,28;,
  4;30,38,37,29;,
  4;31,39,38,30;,
  4;32,40,39,31;,
  4;25,33,40,32;,
  4;34,42,41,33;,
  4;35,43,42,34;,
  4;36,44,43,35;,
  4;37,45,44,36;,
  4;38,46,45,37;,
  4;39,47,46,38;,
  4;40,48,47,39;,
  4;33,41,48,40;,
  4;241,50,49,242;,
  4;243,51,50,241;,
  4;244,52,51,243;,
  4;245,53,52,244;,
  4;246,54,53,245;,
  4;247,55,54,246;,
  4;248,56,55,247;,
  4;242,49,56,248;,
  4;50,1,0,49;,
  4;51,2,1,50;,
  4;52,3,2,51;,
  4;53,4,3,52;,
  4;54,5,4,53;,
  4;55,6,5,54;,
  4;56,7,6,55;,
  4;49,0,7,56;,
  3;65,67,66;,
  3;65,66,68;,
  3;65,68,69;,
  3;65,69,70;,
  3;65,70,71;,
  3;65,71,72;,
  3;65,72,73;,
  3;65,73,67;,
  4;58,66,67,57;,
  4;59,68,66,58;,
  4;60,69,68,59;,
  4;61,70,69,60;,
  4;62,71,70,61;,
  4;63,72,71,62;,
  4;64,73,72,63;,
  4;57,67,73,64;,
  4;103,106,105,104;,
  4;106,108,107,105;,
  4;108,110,109,107;,
  4;110,112,111,109;,
  4;112,114,113,111;,
  4;114,116,115,113;,
  4;116,118,117,115;,
  4;118,120,119,117;,
  4;120,122,121,119;,
  4;122,103,104,121;,
  4;104,105,124,123;,
  4;105,107,125,124;,
  4;107,109,126,125;,
  4;109,111,127,126;,
  4;111,113,128,127;,
  4;113,115,129,128;,
  4;115,117,130,129;,
  4;117,119,131,130;,
  4;119,121,132,131;,
  4;121,104,123,132;,
  4;123,124,134,133;,
  4;124,125,135,134;,
  4;125,126,136,249;,
  4;126,127,137,136;,
  4;127,128,138,137;,
  4;128,129,139,138;,
  4;129,130,140,250;,
  4;130,131,141,140;,
  4;131,132,142,141;,
  4;132,123,133,142;,
  4;133,134,144,143;,
  4;134,135,145,144;,
  4;249,136,146,251;,
  4;136,137,147,146;,
  4;137,138,148,147;,
  4;138,139,149,148;,
  3;151,150,140;,
  3;140,150,250;,
  3;250,150,252;,
  4;140,141,152,151;,
  4;141,142,153,152;,
  4;142,133,143,153;,
  4;143,144,155,154;,
  4;144,145,156,155;,
  4;253,157,157,253;,
  4;157,158,158,157;,
  4;158,159,159,158;,
  4;159,160,160,159;,
  4;252,150,161,254;,
  4;151,152,163,162;,
  4;152,153,164,163;,
  4;153,143,154,164;,
  4;154,155,166,165;,
  4;255,256,167,166;,
  4;74,75,80,79;,
  4;75,76,81,80;,
  4;76,77,82,81;,
  4;77,78,83,82;,
  4;78,89,90,83;,
  4;162,163,169,168;,
  4;163,164,170,169;,
  4;164,154,165,170;,
  4;165,166,172,171;,
  4;257,167,173,257;,
  4;84,85,85,84;,
  4;80,258,86,259;,
  4;258,260,87,86;,
  4;260,83,88,87;,
  4;91,90,91,91;,
  4;168,169,175,174;,
  4;169,170,176,175;,
  4;170,165,171,176;,
  4;171,172,178,177;,
  4;172,173,179,178;,
  4;261,180,180,262;,
  4;180,181,181,180;,
  4;181,182,182,181;,
  4;182,183,183,182;,
  3;174,184,185;,
  3;263,264,184;,
  3;265,266,265;,
  4;174,267,186,184;,
  4;175,176,187,186;,
  4;176,171,177,187;,
  3;93,92,102;,
  3;94,93,102;,
  3;95,94,102;,
  3;96,95,102;,
  3;97,96,102;,
  3;98,97,102;,
  3;99,98,102;,
  3;100,99,102;,
  3;101,100,102;,
  3;92,101,102;,
  3;177,178,188;,
  3;178,179,188;,
  3;179,268,188;,
  3;268,269,188;,
  3;269,270,188;,
  3;270,263,188;,
  3;263,184,188;,
  3;184,186,188;,
  3;186,187,188;,
  3;187,177,188;,
  4;161,150,151,162;,
  4;189,161,162,168;,
  4;185,189,168,174;,
  4;271,271,272,272;,
  4;273,273,271,271;,
  4;274,274,273,273;,
  4;275,275,274,274;,
  4;276,276,275,275;,
  4;277,277,276,276;,
  4;278,278,277,277;,
  4;279,279,278,278;,
  4;280,280,279,279;,
  4;272,272,280,280;,
  4;74,256,281,75;,
  4;75,281,282,76;,
  4;76,282,283,77;,
  4;77,283,284,78;,
  4;78,284,285,89;,
  4;286,286,286,286;,
  4;84,261,287,84;,
  4;259,288,289,289;,
  4;86,290,288,259;,
  4;87,291,290,86;,
  4;88,266,291,87;,
  4;292,292,293,293;,
  4;294,294,295,295;,
  4;295,295,292,292;,
  4;206,209,208,207;,
  4;296,211,210,296;,
  4;211,213,212,210;,
  4;297,215,214,298;,
  4;215,217,216,214;,
  4;217,219,218,216;,
  4;219,221,220,218;,
  4;299,206,207,299;,
  4;207,208,223,222;,
  4;208,210,224,223;,
  4;210,212,225,224;,
  4;212,214,226,225;,
  4;214,216,227,226;,
  4;216,218,228,227;,
  4;218,220,229,228;,
  4;220,207,222,229;,
  4;222,223,231,230;,
  4;223,224,232,231;,
  4;224,225,233,232;,
  4;225,226,234,233;,
  4;226,227,235,234;,
  4;227,228,236,235;,
  4;228,229,237,236;,
  4;229,222,230,237;,
  4;190,191,199,198;,
  4;191,192,200,199;,
  4;192,193,201,200;,
  4;300,194,202,301;,
  4;194,195,203,202;,
  4;195,196,204,203;,
  4;196,197,197,204;,
  4;302,190,198,302;,
  3;209,303,238;,
  3;304,209,238;,
  3;297,304,238;,
  3;305,213,238;,
  3;217,305,238;,
  3;219,217,238;,
  3;306,306,238;,
  3;303,221,238;,
  3;198,199,205;,
  3;199,200,205;,
  3;200,201,205;,
  3;201,202,205;,
  3;202,203,205;,
  3;203,204,205;,
  3;204,307,205;,
  3;308,198,308;,
  4;309,309,310,310;,
  4;310,310,311,311;,
  4;311,311,312,313;,
  4;300,312,314,194;,
  4;194,314,315,195;,
  4;195,315,316,196;,
  4;196,316,317,317;,
  4;317,317,309,309;;
 }
 MeshTextureCoords {
  291;
  0.908400;0.074570;,
  0.870520;0.074570;,
  0.870520;0.059060;,
  0.908400;0.062570;,
  0.908400;0.086570;,
  0.870520;0.090090;,
  0.908400;0.091540;,
  0.870520;0.096510;,
  0.908400;0.086570;,
  0.870520;0.090090;,
  0.908400;0.074570;,
  0.870520;0.074570;,
  0.908400;0.062570;,
  0.870520;0.059060;,
  0.908400;0.057600;,
  0.870520;0.052630;,
  0.847680;0.074570;,
  0.847680;0.074570;,
  0.870520;0.074570;,
  0.870520;0.042090;,
  0.847680;0.049240;,
  0.847680;0.099900;,
  0.870520;0.107060;,
  0.847680;0.110390;,
  0.870520;0.120510;,
  0.847680;0.099900;,
  0.870520;0.107060;,
  0.847680;0.074570;,
  0.870520;0.074570;,
  0.847680;0.049240;,
  0.870520;0.042090;,
  0.847680;0.038750;,
  0.870520;0.028630;,
  0.908400;0.074570;,
  0.908400;0.038570;,
  0.908400;0.110570;,
  0.908400;0.125480;,
  0.908400;0.110570;,
  0.908400;0.074570;,
  0.908400;0.038570;,
  0.908400;0.023660;,
  0.951360;0.074570;,
  0.951360;0.042090;,
  0.951360;0.107060;,
  0.951360;0.120510;,
  0.951360;0.107060;,
  0.951360;0.074570;,
  0.951360;0.042090;,
  0.951360;0.028630;,
  0.978430;0.074570;,
  0.978430;0.050570;,
  0.978430;0.098570;,
  0.978430;0.108510;,
  0.978430;0.098570;,
  0.978430;0.074570;,
  0.978430;0.050570;,
  0.978430;0.040630;,
  0.951360;0.074570;,
  0.951360;0.059060;,
  0.951360;0.090090;,
  0.951360;0.096510;,
  0.951360;0.090090;,
  0.951360;0.074570;,
  0.951360;0.059060;,
  0.951360;0.052630;,
  0.831040;0.074570;,
  0.839850;0.058250;,
  0.839850;0.051490;,
  0.839850;0.058250;,
  0.839850;0.074570;,
  0.839850;0.090890;,
  0.839850;0.097650;,
  0.839850;0.090890;,
  0.839850;0.074570;,
  0.353880;0.564800;,
  0.414220;0.606840;,
  0.384240;0.711250;,
  0.268280;0.631190;,
  0.487430;0.600800;,
  0.750030;0.774850;,
  0.546550;0.551180;,
  0.778730;0.617810;,
  0.567370;0.485140;,
  0.774110;0.477470;,
  0.541140;0.421040;,
  0.767030;0.336570;,
  0.478100;0.376480;,
  0.725390;0.182430;,
  0.404640;0.376510;,
  0.366130;0.275750;,
  0.348000;0.423400;,
  0.257200;0.364800;,
  0.328230;0.495030;,
  0.218800;0.499820;,
  0.356880;0.804990;,
  0.190360;0.691670;,
  0.834940;0.777840;,
  0.861610;0.618380;,
  0.852120;0.474500;,
  0.849600;0.329800;,
  0.809800;0.173590;,
  0.331120;0.185870;,
  0.174590;0.312480;,
  0.120480;0.504650;,
  0.339930;0.863430;,
  0.141110;0.731150;,
  0.892370;0.788160;,
  0.912150;0.624920;,
  0.910870;0.473590;,
  0.899580;0.322780;,
  0.866320;0.162100;,
  0.309520;0.132440;,
  0.122370;0.280650;,
  0.058550;0.508930;,
  0.333440;0.883640;,
  0.124200;0.745220;,
  0.944260;0.787970;,
  0.959680;0.624440;,
  0.962580;0.473190;,
  0.947130;0.322880;,
  0.918110;0.161370;,
  0.301780;0.116360;,
  0.591380;0.130370;,
  0.104500;0.271680;,
  0.037420;0.511630;,
  0.334630;0.861550;,
  0.139270;0.735160;,
  0.834590;0.763600;,
  0.855980;0.629010;,
  0.868100;0.481120;,
  0.843330;0.334680;,
  0.812060;0.171700;,
  0.601320;0.141350;,
  0.119300;0.284430;,
  0.309750;0.137040;,
  0.055480;0.512710;,
  0.353760;0.792240;,
  0.189420;0.703130;,
  0.715970;0.767430;,
  0.969610;0.099090;,
  0.970770;0.099400;,
  0.875600;0.116040;,
  0.902400;0.072480;,
  0.978730;0.102880;,
  0.879560;0.121490;,
  0.962480;0.102240;,
  0.867710;0.118750;,
  0.952990;0.104790;,
  0.851250;0.114930;,
  0.820450;0.019900;,
  0.821560;0.021060;,
  0.165350;0.317690;,
  0.332380;0.192300;,
  0.111010;0.512070;,
  0.386980;0.719490;,
  0.271310;0.643850;,
  0.735030;0.779220;,
  0.843730;0.073790;,
  0.917200;0.078020;,
  0.841260;0.077710;,
  0.835740;0.076520;,
  0.823240;0.057620;,
  0.821410;0.025440;,
  0.251720;0.376470;,
  0.369310;0.291520;,
  0.213480;0.509240;,
  0.672410;0.587490;,
  0.624370;0.557010;,
  0.724270;0.578850;,
  0.620480;0.630730;,
  0.752650;0.533110;,
  0.617620;0.489950;,
  0.769310;0.480540;,
  0.606540;0.358160;,
  0.749840;0.433120;,
  0.599730;0.200370;,
  0.707130;0.402170;,
  0.670240;0.378180;,
  0.613440;0.207190;,
  0.618090;0.432990;,
  0.601130;0.488270;,
  0.866340;0.056060;,
  0.815550;0.055970;,
  0.893260;0.054440;,
  0.927270;0.056680;,
  0.975080;0.057590;,
  0.991500;0.058450;,
  0.970260;0.058920;,
  0.919470;0.058830;,
  0.858530;0.058210;,
  0.810730;0.057300;,
  0.794310;0.056440;,
  0.698830;0.483970;,
  0.611750;0.176160;,
  0.415400;0.598600;,
  0.357770;0.560280;,
  0.484550;0.595740;,
  0.538800;0.552780;,
  0.557430;0.486140;,
  0.533330;0.421260;,
  0.475690;0.382930;,
  0.406550;0.385800;,
  0.352300;0.428760;,
  0.333670;0.495400;,
  0.818850;0.773320;,
  0.820590;0.627680;,
  0.832550;0.482290;,
  0.808130;0.338320;,
  0.793880;0.193450;,
  0.594690;0.177730;,
  0.717850;0.772710;,
  0.740090;0.772240;,
  0.629670;0.629650;,
  0.805680;0.093870;,
  0.798330;0.066430;,
  0.800850;0.061440;,
  0.808950;0.088670;,
  0.798380;0.092300;,
  0.788570;0.066140;,
  0.598880;0.202760;,
  0.617670;0.350950;,
  0.596140;0.229260;,
  0.596360;0.205510;,
  0.100330;0.290190;,
  0.063630;0.297820;,
  0.211200;0.215400;,
  0.258980;0.241090;,
  0.034010;0.348530;,
  0.288450;0.316360;,
  0.037340;0.369970;,
  0.269650;0.421810;,
  0.036610;0.389300;,
  0.290420;0.521940;,
  0.072380;0.399560;,
  0.327360;0.549340;,
  0.099640;0.362510;,
  0.362530;0.508730;,
  0.145530;0.320850;,
  0.383310;0.409170;,
  0.418270;0.266010;,
  0.462620;0.300580;,
  0.382580;0.312880;,
  0.374570;0.416990;,
  0.401150;0.515040;,
  0.441890;0.546160;,
  0.476680;0.502250;,
  0.486470;0.402620;,
  0.783170;0.138930;,
  0.797710;0.160630;,
  0.773630;0.185390;,
  0.817070;0.289160;,
  0.891190;0.387890;,
  0.951650;0.421550;,
  0.965990;0.375200;,
  0.925570;0.277010;,
  0.929680;0.105470;,
  0.933830;0.105470;,
  0.933830;0.092980;,
  0.929680;0.092980;,
  0.937980;0.105470;,
  0.937980;0.092980;,
  0.942140;0.105470;,
  0.942140;0.092980;,
  0.946290;0.105470;,
  0.946290;0.092980;,
  0.950440;0.105470;,
  0.950440;0.092980;,
  0.954600;0.105470;,
  0.954600;0.092980;,
  0.958750;0.105470;,
  0.958750;0.092980;,
  0.962910;0.105470;,
  0.962910;0.092980;,
  0.062350;0.366340;,
  0.960980;0.057650;,
  0.946290;0.051560;,
  0.946290;0.073160;,
  0.931600;0.057650;,
  0.925520;0.072330;,
  0.931600;0.087020;,
  0.946290;0.093100;,
  0.960980;0.087020;,
  0.967060;0.072330;,
  0.799950;0.192740;,
  0.801940;0.187810;,
  0.795410;0.219310;,
  0.833130;0.286310;,
  0.892990;0.349580;,
  0.939930;0.372050;,
  0.946440;0.340560;,
  0.908720;0.273550;;
 }
}
