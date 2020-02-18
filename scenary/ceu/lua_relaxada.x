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

 Frame Frame1_Unnamed {

  FrameTransformMatrix {
   1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000;;
  }

  Mesh Mesh_Unnamed {
   24;
   0.000000;100.449997;-4.500000;,
   0.000000;97.042580;-30.381897;,
   0.000000;87.052536;-54.500000;,
   0.000000;71.160675;-75.210663;,
   0.000000;50.450001;-91.102539;,
   0.000000;26.331903;-101.092590;,
   0.000000;0.450000;-104.500000;,
   0.000000;-25.431904;-101.092590;,
   0.000000;-49.549999;-91.102539;,
   0.000000;-70.260674;-75.210663;,
   0.000000;-86.152542;-54.500000;,
   0.000000;-96.142578;-30.381897;,
   0.000000;-99.550003;-4.500000;,
   0.000000;-96.142578;21.381897;,
   0.000000;-86.152542;45.500000;,
   0.000000;-70.260674;66.210678;,
   0.000000;-49.549999;82.102539;,
   0.000000;-25.431904;92.092590;,
   0.000000;0.450000;95.500000;,
   0.000000;26.331903;92.092590;,
   0.000000;50.450001;82.102539;,
   0.000000;71.160675;66.210678;,
   0.000000;87.052536;45.500000;,
   0.000000;97.042580;21.381897;;
   22;
   3;0,13,12;,
   3;0,23,22;,
   3;0,22,21;,
   3;0,21,20;,
   3;0,20,19;,
   3;0,19,18;,
   3;0,18,17;,
   3;0,17,16;,
   3;0,16,15;,
   3;0,15,14;,
   3;0,14,13;,
   3;0,2,1;,
   3;0,12,11;,
   3;0,11,10;,
   3;0,10,9;,
   3;0,9,8;,
   3;0,8,7;,
   3;0,7,6;,
   3;0,6,5;,
   3;0,5,4;,
   3;0,4,3;,
   3;0,3,2;;

   MeshNormals {
    24;
    1.000000;0.000000;0.000000;,
    1.000000;0.000000;0.000000;,
    1.000000;0.000000;0.000000;,
    1.000000;0.000000;0.000000;,
    1.000000;0.000000;0.000000;,
    1.000000;0.000000;0.000000;,
    1.000000;0.000000;0.000000;,
    1.000000;0.000000;0.000000;,
    1.000000;0.000000;0.000000;,
    1.000000;0.000000;0.000000;,
    1.000000;0.000000;0.000000;,
    1.000000;0.000000;0.000000;,
    1.000000;0.000000;0.000000;,
    1.000000;0.000000;0.000000;,
    1.000000;0.000000;0.000000;,
    1.000000;0.000000;0.000000;,
    1.000000;0.000000;0.000000;,
    1.000000;0.000000;0.000000;,
    1.000000;0.000000;0.000000;,
    1.000000;0.000000;0.000000;,
    1.000000;0.000000;0.000000;,
    1.000000;0.000000;0.000000;,
    1.000000;0.000000;0.000000;,
    1.000000;0.000000;0.000000;;
    22;
    3;0,13,12;,
    3;0,23,22;,
    3;0,22,21;,
    3;0,21,20;,
    3;0,20,19;,
    3;0,19,18;,
    3;0,18,17;,
    3;0,17,16;,
    3;0,16,15;,
    3;0,15,14;,
    3;0,14,13;,
    3;0,2,1;,
    3;0,12,11;,
    3;0,11,10;,
    3;0,10,9;,
    3;0,9,8;,
    3;0,8,7;,
    3;0,7,6;,
    3;0,6,5;,
    3;0,5,4;,
    3;0,4,3;,
    3;0,3,2;;
   }

   MeshTextureCoords {
    24;
    1.000000;0.500000;,
    0.982963;0.370590;,
    0.933013;0.250000;,
    0.853553;0.146447;,
    0.750000;0.066987;,
    0.629410;0.017037;,
    0.500000;0.000000;,
    0.370591;0.017037;,
    0.250000;0.066987;,
    0.146447;0.146447;,
    0.066987;0.250000;,
    0.017037;0.370590;,
    0.000000;0.500000;,
    0.017037;0.629410;,
    0.066987;0.750000;,
    0.146447;0.853553;,
    0.250000;0.933013;,
    0.370591;0.982963;,
    0.500000;1.000000;,
    0.629410;0.982963;,
    0.750000;0.933013;,
    0.853553;0.853553;,
    0.933013;0.750000;,
    0.982963;0.629410;;
   }

   MeshMaterialList {
    5;
    22;
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
      "lua_p.jpg";
     }
    }

    Material {
     1.000000;1.000000;1.000000;1.000000;;
     51.200001;
     0.000000;0.000000;0.000000;;
     0.000000;0.000000;0.000000;;
     TextureFilename {
      "lua_p.jpg";
     }
    }

    Material {
     1.000000;1.000000;1.000000;1.000000;;
     51.200001;
     0.000000;0.000000;0.000000;;
     0.000000;0.000000;0.000000;;
     TextureFilename {
      "lua_p.jpg";
     }
    }

    Material {
     1.000000;1.000000;1.000000;1.000000;;
     51.200001;
     0.000000;0.000000;0.000000;;
     0.000000;0.000000;0.000000;;
     TextureFilename {
      "lua_p.jpg";
     }
    }
   }
  }
 }
}
