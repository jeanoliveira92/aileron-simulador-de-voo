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

 Frame Frame1_mob_rudderBoard {

  FrameTransformMatrix {
   1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000;;
  }

  Mesh Mesh_mob_rudderBoard {
   23;
   0.423252;-0.033080;0.026199;,
   0.423252;-0.033080;0.026199;,
   -0.422073;-0.033080;0.026199;,
   -0.422073;-0.033080;0.026199;,
   -0.305134;8.752919;-5.870992;,
   -0.305134;8.752919;-5.870992;,
   0.308254;8.752919;-5.870992;,
   0.308254;8.752919;-5.870992;,
   -0.423252;-0.033080;0.026199;,
   -0.423252;-0.033080;0.026199;,
   0.422073;-0.033080;0.026199;,
   0.422073;-0.033080;0.026199;,
   0.305134;8.752919;-5.870992;,
   0.305134;8.752919;-5.870992;,
   -0.308254;8.752919;-5.870992;,
   -0.308254;8.752919;-5.870992;,
   0.003395;8.752919;-7.318318;,
   0.003395;8.752919;-7.318318;,
   0.003395;8.752919;-7.318318;,
   0.008072;-1.045081;-4.021794;,
   0.008072;-1.045081;-4.021794;,
   0.008072;-1.045081;-4.021794;,
   0.008072;-1.045081;-4.021794;;
   18;
   3;19,12,10;,
   3;20,4,16;,
   3;0,6,5;,
   3;2,0,5;,
   3;21,1,3;,
   3;3,4,1;,
   3;1,4,7;,
   3;22,2,0;,
   3;17,5,6;,
   3;20,3,4;,
   3;19,18,12;,
   3;11,13,8;,
   3;8,13,14;,
   3;21,10,9;,
   3;10,9,12;,
   3;9,15,12;,
   3;22,8,11;,
   3;17,14,13;;

   MeshNormals {
    23;
    0.000000;0.826844;0.562431;,
    0.000000;-0.826844;-0.562431;,
    0.000000;0.933286;0.359134;,
    -0.501029;-0.794487;-0.343163;,
    -0.647600;-0.405799;-0.644936;,
    0.000000;0.786474;0.617623;,
    0.000000;0.882413;0.470476;,
    0.000000;-0.557305;-0.830308;,
    0.000000;0.826844;0.562431;,
    0.000000;-0.826844;-0.562431;,
    0.501932;-0.794443;-0.341943;,
    0.000000;0.933286;0.359134;,
    0.649349;-0.405052;-0.643645;,
    0.000000;0.786474;0.617623;,
    0.000000;0.882413;0.470476;,
    0.000000;-0.557305;-0.830308;,
    -0.975596;-0.070437;-0.207969;,
    0.000000;1.000000;0.000000;,
    0.976683;-0.068041;-0.203619;,
    0.690655;-0.720066;0.067084;,
    -0.689691;-0.721240;0.064343;,
    0.000692;-0.998728;-0.050408;,
    0.000000;0.970142;-0.242536;;
    18;
    3;19,12,10;,
    3;20,4,16;,
    3;0,6,5;,
    3;2,0,5;,
    3;21,1,3;,
    3;3,4,1;,
    3;1,4,7;,
    3;22,2,0;,
    3;17,5,6;,
    3;20,3,4;,
    3;19,18,12;,
    3;11,13,8;,
    3;8,13,14;,
    3;21,10,9;,
    3;10,9,12;,
    3;9,15,12;,
    3;22,8,11;,
    3;17,14,13;;
   }

   MeshTextureCoords {
    23;
    0.411727;0.816039;,
    0.411727;0.816039;,
    0.411727;0.816039;,
    0.411727;0.816039;,
    0.110814;0.128507;,
    0.110814;0.128507;,
    0.110814;0.128507;,
    0.110814;0.128507;,
    0.411727;0.816039;,
    0.411727;0.816039;,
    0.411727;0.816039;,
    0.411727;0.816039;,
    0.110814;0.128507;,
    0.110814;0.128507;,
    0.110814;0.128507;,
    0.110814;0.128507;,
    0.036877;0.128507;,
    0.036963;0.128507;,
    0.036877;0.128507;,
    0.205172;0.895231;,
    0.205172;0.895231;,
    0.205172;0.895231;,
    0.205172;0.895231;;
   }

   VertexDuplicationIndices {
    23;
    20;
    0,
    0,
    2,
    2,
    4,
    4,
    6,
    6,
    8,
    8,
    10,
    10,
    12,
    12,
    14,
    14,
    16,
    16,
    16,
    19,
    19,
    19,
    19;
   }

   MeshMaterialList {
    2;
    18;
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
     TextureFilename {
      "leme.bmp";
     }
    }
   }
  }
 }
}
