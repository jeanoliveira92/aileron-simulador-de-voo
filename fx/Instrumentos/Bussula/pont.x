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
   0.000000;0.000000;0.010000;,
   0.000000;0.002588;0.009659;,
   0.000000;0.005000;0.008660;,
   0.000000;0.007071;0.007071;,
   0.000000;0.008660;0.005000;,
   0.000000;0.009659;0.002588;,
   0.000000;0.010000;0.000000;,
   0.000000;0.009659;-0.002588;,
   0.000000;0.008660;-0.005000;,
   0.000000;0.007071;-0.007071;,
   0.000000;0.005000;-0.008660;,
   0.000000;0.002588;-0.009659;,
   0.000000;0.000000;-0.010000;,
   0.000000;-0.002588;-0.009659;,
   0.000000;-0.005000;-0.008660;,
   0.000000;-0.007071;-0.007071;,
   0.000000;-0.008660;-0.005000;,
   0.000000;-0.009659;-0.002588;,
   0.000000;-0.010000;0.000000;,
   0.000000;-0.009659;0.002588;,
   0.000000;-0.008660;0.005000;,
   0.000000;-0.007071;0.007071;,
   0.000000;-0.005000;0.008660;,
   0.000000;-0.002588;0.009659;;
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
    0.982963;0.370591;,
    0.933013;0.250000;,
    0.853553;0.146447;,
    0.750000;0.066987;,
    0.629409;0.017037;,
    0.500000;0.000000;,
    0.370590;0.017037;,
    0.250000;0.066987;,
    0.146447;0.146447;,
    0.066987;0.250000;,
    0.017037;0.370591;,
    0.000000;0.500000;,
    0.017037;0.629410;,
    0.066987;0.750000;,
    0.146447;0.853553;,
    0.250000;0.933013;,
    0.370590;0.982963;,
    0.500000;1.000000;,
    0.629409;0.982963;,
    0.750000;0.933013;,
    0.853553;0.853553;,
    0.933013;0.750000;,
    0.982963;0.629410;;
   }

   MeshMaterialList {
    2;
    22;
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0;

    Material {
     1.000000;1.000000;1.000000;1.000000;;
     51.200001;
     0.000000;0.000000;0.000000;;
     0.000000;0.000000;0.000000;;
     TextureFilename {
      "pontinho.jpg";
     }
    }

    Material {
     0.784314;0.784314;0.784314;1.000000;;
     51.200001;
     0.000000;0.000000;0.000000;;
     0.000000;0.000000;0.000000;;
    }
   }
  }
 }
}
