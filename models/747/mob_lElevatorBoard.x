xof 0303txt 0032

template XSkinMeshHeader {
 <3cf169ce-ff7c-44ab-93c0-f78f62d172e2>
 WORD nMaxSkinWeightsPerVertex;
 WORD nMaxSkinWeightsPerFace;
 WORD nBones;
}

template VertexDuplicationIndices {
 <b8d65549-d7c9-4995-89cf-53a9a8b031e3>
 DWORD nIndices;
 DWORD nOriginalVertices;
 array DWORD indices[nIndices];
}

template SkinWeights {
 <6f0d123b-bad2-4167-a0d0-80224f25fabb>
 STRING transformNodeName;
 DWORD nWeights;
 array DWORD vertexIndices[nWeights];
 array FLOAT weights[nWeights];
 Matrix4x4 matrixOffset;
}


Frame Frame_SCENE_ROOT {

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000;;
 }

 Frame Frame1_mob_lElevatorBoard {

  FrameTransformMatrix {
   1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000;;
  }

  Mesh Mesh_mob_lElevatorBoard {
   20;
   -5.507456;0.076486;-0.648312;,
   -5.507456;0.076486;-0.648312;,
   -5.508717;-0.073546;-0.653017;,
   -5.508717;-0.073546;-0.653017;,
   -5.622937;0.010785;-1.079294;,
   -5.622937;0.010785;-1.079294;,
   -5.622937;0.010785;-1.079294;,
   4.627933;0.010785;-2.634115;,
   4.777542;0.232019;-2.075766;,
   5.336063;0.324697;0.008666;,
   5.336063;0.324697;0.008666;,
   5.336063;0.324697;0.008666;,
   5.336063;0.324697;0.008666;,
   4.777542;-0.211543;-2.075766;,
   5.339617;-0.370559;0.021927;,
   5.339617;-0.370559;0.021927;,
   5.339617;-0.370559;0.021927;,
   -5.341859;0.119447;-0.030297;,
   -5.336504;-0.118571;-0.010311;,
   -5.336504;-0.118571;-0.010311;;
   16;
   3;7,4,0;,
   3;18,17,2;,
   3;2,17,1;,
   3;13,7,8;,
   3;13,8,9;,
   3;14,13,9;,
   3;13,3,7;,
   3;3,5,7;,
   3;2,1,6;,
   3;7,0,8;,
   3;17,10,8;,
   3;0,17,8;,
   3;15,19,13;,
   3;13,19,3;,
   3;16,11,18;,
   3;18,12,17;;

   MeshNormals {
    20;
    -0.036600;0.981396;-0.188471;,
    -0.965926;-0.000000;0.258819;,
    -0.965926;-0.000000;0.258819;,
    -0.037674;-0.978367;-0.203418;,
    -0.021979;0.989201;-0.144908;,
    -0.028316;-0.982011;-0.186687;,
    -0.965926;-0.000000;0.258819;,
    0.520241;0.005156;-0.854004;,
    0.509016;0.816909;-0.271225;,
    0.965926;0.000000;-0.258819;,
    -0.016815;0.749065;0.662283;,
    -0.003908;0.051333;0.998674;,
    -0.011965;0.490514;0.871351;,
    0.658495;-0.690887;-0.298427;,
    0.965926;0.000000;-0.258819;,
    -0.023330;-0.997320;-0.069351;,
    -0.002569;0.019057;0.999815;,
    -0.618702;0.650059;0.441171;,
    -0.396068;0.041737;0.917272;,
    -0.022779;-0.997517;-0.066645;;
    16;
    3;7,4,0;,
    3;18,17,2;,
    3;2,17,1;,
    3;13,7,8;,
    3;13,8,9;,
    3;14,13,9;,
    3;13,3,7;,
    3;3,5,7;,
    3;2,1,6;,
    3;7,0,8;,
    3;17,10,8;,
    3;0,17,8;,
    3;15,19,13;,
    3;13,19,3;,
    3;16,11,18;,
    3;18,12,17;;
   }

   MeshTextureCoords {
    20;
    0.134609;0.916301;,
    0.134609;0.916301;,
    0.134609;0.916723;,
    0.134609;0.916723;,
    0.134609;0.954993;,
    0.134609;0.954993;,
    0.134609;0.954993;,
    0.852893;0.855156;,
    0.852893;0.805029;,
    0.852893;0.617895;,
    0.852893;0.617895;,
    0.852893;0.617895;,
    0.852893;0.617895;,
    0.852893;0.805029;,
    0.852893;0.616704;,
    0.852893;0.616704;,
    0.852893;0.616704;,
    0.134609;0.860817;,
    0.134609;0.859022;,
    0.134609;0.859022;;
   }

   VertexDuplicationIndices {
    20;
    19;
    0,
    0,
    2,
    2,
    4,
    4,
    4,
    7,
    8,
    9,
    9,
    9,
    9,
    13,
    14,
    14,
    14,
    17,
    18,
    18;
   }

   MeshMaterialList {
    2;
    16;
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1;

    Material {
     0.784314;0.784314;0.784314;1.000000;;
     51.200001;
     0.000000;0.000000;0.000000;;
     0.000000;0.000000;0.000000;;
    }

    Material {
     1.000000;1.000000;1.000000;1.000000;;
     51.200001;
     0.000000;0.000000;0.000000;;
     0.000000;0.000000;0.000000;;
    }
   }
  }
 }
}
