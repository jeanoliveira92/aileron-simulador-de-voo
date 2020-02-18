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

 Frame Frame1_mob_lFlap {

  FrameTransformMatrix {
   1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000;;
  }

  Mesh Mesh_mob_lFlap {
   18;
   1.130023;0.019421;-0.009300;,
   1.130023;0.019421;-0.009300;,
   1.130023;0.019421;-0.009300;,
   -1.129386;0.031018;-0.009300;,
   -1.129386;0.031018;-0.009300;,
   -1.129386;0.031018;-0.009300;,
   1.129538;-0.026908;-0.009300;,
   1.129538;-0.026908;-0.009300;,
   1.129538;-0.026908;-0.009300;,
   -1.129870;-0.015193;-0.009300;,
   -1.129870;-0.015193;-0.009300;,
   -1.129870;-0.015193;-0.009300;,
   1.129741;-0.007449;-0.221651;,
   1.129741;-0.007449;-0.221651;,
   1.129741;-0.007449;-0.221651;,
   -1.129721;-0.000965;-0.221114;,
   -1.129721;-0.000965;-0.221114;,
   -1.129721;-0.000965;-0.221114;;
   9;
   3;6,0,3;,
   3;9,4,15;,
   3;9,4,15;,
   3;6,3,10;,
   3;7,12,1;,
   3;8,11,16;,
   3;8,16,13;,
   3;14,5,2;,
   3;14,17,5;;

   MeshNormals {
    18;
    0.000000;0.000000;1.000000;,
    0.999945;-0.010472;-0.000001;,
    0.005092;0.992075;-0.125541;,
    0.000000;0.000000;1.000000;,
    -0.999945;0.010475;-0.000000;,
    0.003948;0.990503;-0.137434;,
    0.000000;0.000000;1.000000;,
    0.999945;-0.010472;-0.000001;,
    -0.004027;-0.996855;-0.079145;,
    -0.999945;0.010475;-0.000000;,
    0.000000;0.000000;1.000000;,
    -0.005173;-0.997738;-0.067026;,
    0.999945;-0.010472;-0.000001;,
    -0.002880;-0.995824;-0.091252;,
    0.003948;0.990503;-0.137434;,
    -0.999945;0.010475;-0.000000;,
    -0.004027;-0.996855;-0.079145;,
    0.002802;0.988787;-0.149306;;
    9;
    3;6,0,3;,
    3;9,4,15;,
    3;9,4,15;,
    3;6,3,10;,
    3;7,12,1;,
    3;8,11,16;,
    3;8,16,13;,
    3;14,5,2;,
    3;14,17,5;;
   }

   MeshTextureCoords {
    18;
    0.000000;1.000000;,
    0.000000;1.000000;,
    0.436483;0.447000;,
    0.000000;1.000000;,
    0.000000;1.000000;,
    0.436483;0.186000;,
    0.000000;1.000000;,
    0.000000;1.000000;,
    0.580913;0.447000;,
    0.000000;1.000000;,
    0.000000;1.000000;,
    0.580913;0.186000;,
    0.000000;1.000000;,
    0.605000;0.447000;,
    0.461000;0.447000;,
    0.000000;1.000000;,
    0.605000;0.186000;,
    0.460938;0.186000;;
   }

   VertexDuplicationIndices {
    18;
    16;
    0,
    0,
    0,
    3,
    3,
    3,
    6,
    6,
    6,
    9,
    9,
    9,
    12,
    12,
    12,
    15,
    15,
    15;
   }

   MeshMaterialList {
    3;
    9;
    0,
    0,
    0,
    0,
    0,
    2,
    2,
    2,
    2;

    Material {
     1.000000;1.000000;1.000000;1.000000;;
     51.200001;
     0.000000;0.000000;0.000000;;
     0.000000;0.000000;0.000000;;
    }

    Material {
     0.784314;0.784314;0.784314;1.000000;;
     51.200001;
     0.000000;0.000000;0.000000;;
     0.000000;0.000000;0.000000;;
    }

    Material {
     1.000000;1.000000;1.000000;1.000000;;
     34.559998;
     0.000000;0.000000;0.000000;;
     0.000000;0.000000;0.000000;;
     TextureFilename {
      "Jabiru_160C_paint2.png";
     }
    }
   }
  }
 }
}
