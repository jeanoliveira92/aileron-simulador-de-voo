#include "instrumentos.h"

Painel :: Painel(ISceneManager* smgrPainel, stringw name, IVideoDriver* driver, ITimer *my_timer,IGUIEnvironment * guienvPainel)
{
    myguienv = guienvPainel;
    myguienv->addImage(driver->getTexture("fx/Instrumentos/Fuel/fuel.png"),position2d<int>(context.bSizeX, context.bSizeY - 14));


    timer = my_timer;
    mydriver = driver;
    IMesh * mostraAviso = smgrPainel->getMesh("fx/outros/aviso.x");
    aviso = smgrPainel->addMeshSceneNode(mostraAviso);
    aviso->setMaterialFlag(EMF_LIGHTING, false);
    aviso->setMaterialType(EMT_TRANSPARENT_ALPHA_CHANNEL_REF);
    aviso->setMaterialTexture(0,mydriver->getTexture("fx/outros/aviso3.png"));
    aviso->setMaterialTexture(0,mydriver->getTexture("fx/outros/aviso2.png"));
    aviso->setMaterialTexture(0,mydriver->getTexture("fx/outros/aviso1.png"));
    //aviso->setScale(vector3df(1.4, 1.4f, 1.4f));
    aviso->setPosition(vector3df(0.0f, 1.2f, 0.0f));

    IMesh * marcPontinho = smgrPainel->getMesh("fx/Instrumentos/Bussula/pont.x");
    localizar =smgrPainel->addMeshSceneNode(marcPontinho);
    localizar->setMaterialFlag(EMF_LIGHTING, false);
    localizar->setMaterialType(EMT_SOLID);
    //localizar->setScale(vector3df(1.4, 1.4f, 1.4f));
    //localizar->setPosition(vector3df(0.3f, 1.1f, -2.0f));

    IMesh * mapaLocaliza = smgrPainel->getMesh("fx/Instrumentos/Bussula/mapa.x");
    mapa_1 =smgrPainel->addMeshSceneNode(mapaLocaliza);
    mapa_1->setMaterialFlag(EMF_LIGHTING, false);
    mapa_1->setMaterialType(EMT_SOLID);
    mapa_1->setMaterialTexture(0,mydriver->getTexture("fx/Instrumentos/Bussula/Mapa.jpg"));
    mapa_1->setMaterialTexture(0,mydriver->getTexture("fx/Instrumentos/Bussula/mapa_alinhado.jpg"));
    mapa_1->setMaterialTexture(0,mydriver->getTexture("fx/Instrumentos/Bussula/mp_sul.jpg"));
    mapa_1->setMaterialTexture(0,mydriver->getTexture("fx/Instrumentos/Bussula/mp_norte.jpg"));
    mapa_1->setMaterialTexture(0,mydriver->getTexture("fx/Instrumentos/Bussula/mapa_pouso.jpg"));
    mapa_1->setScale(vector3df(1.4, 1.4f, 1.4f));
    mapa_1->setPosition(vector3df(0.0f, 1.1f, -1.4f));


    recName = name;
    Name = &recName;
    IMesh * marVeloz;
    if(*Name == "747")
        marVeloz = smgrPainel->getMesh("fx/Instrumentos/747/Velocimetro.x");
    else if(*Name == "160C")
        marVeloz = smgrPainel->getMesh("fx/Instrumentos/160C/speed_160C.x");
    else
        marVeloz = smgrPainel->getMesh("fx/Instrumentos/thunderbolt/velocimetro.x");

    IMeshSceneNode * veloz = smgrPainel->addMeshSceneNode(marVeloz);
    veloz->setMaterialFlag(EMF_LIGHTING, false);
    veloz->setScale(vector3df(1.4, 1.4f, 1.4f));
    veloz->setPosition(vector3df(0.0f, 0.35f, -1.4f));

    IMesh * pontVeloz = smgrPainel->getMesh("fx/Instrumentos/ponteiros/ponteiro.x");
    marcVeloz = smgrPainel->addMeshSceneNode(pontVeloz);
    marcVeloz->setMaterialFlag(EMF_LIGHTING, false);
    marcVeloz->setParent(veloz);
    marcVeloz->setPosition(vector3df(0.0f, 0.0f, 0.0f));
    if(*Name == "747" || *Name == "160C")
    {
        se_747_ter = 58.0f;//Refere-se ao ajuste do ponteiro de Velocidade
        if(*Name == "747")
            ajeitaPos = 45.0f;//AjeitaPos refere-se ao ajuste do ponteiro de RPM
        else
            ajeitaPos = 38.0f;
    }
    else
    {
        ajeitaPos = 30.0f;
        se_747_ter = 0.0f;
    };

    IMesh * displayRPM;
    if(*Name =="747")
        displayRPM = smgrPainel->getMesh("fx/Instrumentos/747/RPM.x");
    else if(*Name =="160C")
        displayRPM = smgrPainel->getMesh("fx/Instrumentos/160C/RPM_160C.x");
    else
        displayRPM = smgrPainel->getMesh("fx/Instrumentos/thunderbolt/rpm.x");
    IMeshSceneNode * RPM = smgrPainel->addMeshSceneNode(displayRPM);
    RPM->setMaterialFlag(EMF_LIGHTING, false);
    RPM->setScale(vector3df(1.4f, 1.4f, 1.4f));
    RPM->setPosition(vector3df(0.0f, -0.3f, -1.4f));

    IMesh * pontRPM = smgrPainel->getMesh("fx/Instrumentos/ponteiros/ponteiro.x");
    marcRPM = smgrPainel->addMeshSceneNode(pontRPM);
    marcRPM->setMaterialFlag(EMF_LIGHTING, false);
    marcRPM->setParent(RPM);
    marcRPM->setPosition(vector3df(0.0f, 0.0f, 0.0f));

    IMesh * displayAlt;
    if(*Name == "747")
        displayAlt = smgrPainel->getMesh("fx/Instrumentos/747/altimetro.x");
    else if(*Name == "160C")
        displayAlt = smgrPainel->getMesh("fx/Instrumentos/160C/altimetro_160C.x");
    else
        displayAlt = smgrPainel->getMesh("fx/Instrumentos/thunderbolt/altimetro.x");
    IMeshSceneNode * ALT = smgrPainel->addMeshSceneNode(displayAlt);
    ALT->setMaterialFlag(EMF_LIGHTING, false);
    ALT->setScale(vector3df(1.4f, 1.4f, 1.4f));
    ALT->setPosition(vector3df(0.0f, -1.0f, -1.4f));

    IMesh * pontALT = smgrPainel->getMesh("fx/Instrumentos/ponteiros/ponteiro.x");
    marcALT = smgrPainel->addMeshSceneNode(pontALT);
    marcALT->setMaterialFlag(EMF_LIGHTING, false);
    marcALT->setParent(ALT);
    marcALT->setPosition(vector3df(0.0f, 0.0f, 0.0f));

    IMesh * display_Bus = smgrPainel->getMesh("fx/Instrumentos/Bussula/Norteia.x");
    bussula = smgrPainel->addMeshSceneNode(display_Bus);
    bussula->setMaterialFlag(EMF_LIGHTING, false);
    bussula->setScale(vector3df(1.4f, 1.4f, 1.4f));
    bussula->setPosition(vector3df(0.0f, 1.1f, 1.4f));

    IMesh * pontBus = smgrPainel->getMesh("fx/Instrumentos/Bussula/aviao.x");
    IMeshSceneNode * marcBus = smgrPainel->addMeshSceneNode(pontBus);
    marcBus->setMaterialFlag(EMF_LIGHTING, false);
    //marcBus->setParent(bussula);
    marcBus->setPosition(vector3df(0.0f, 1.1f, 1.4f));
    inicia_jogo = true;
    ver1 = true;
    xIni=0;
    voou = false;
    confirmBat =false;
    recTempIni = 0;
    primaVezTemp = true;
    gas = 0;

};
///**************************************************************************
bool Painel :: fuelTemp(int tempo)
{
    if(primaVezTemp)
    {
        recTempIni = tempo + 15000;///Tempo para diminuir o combustivel. !Quantidade em milisegundos;
        primaVezTemp = false;///São 8 imagens então são valor(milisegundos * 8) para acabar a gasolina;
    };
    if (tempo>recTempIni)
    {
        primaVezTemp = true;
        //printf("\nVez %d - %d", gas, recTempIni);
        switch (gas)
        {
            case 0:
               myguienv->addImage(mydriver->getTexture("fx/Instrumentos/Fuel/fuel1.png"),position2d<int>(context.bSizeX, context.bSizeY - 14));
                break;
            case 1:
                myguienv->addImage(mydriver->getTexture("fx/Instrumentos/Fuel/fuel2.png"),position2d<int>(context.bSizeX, context.bSizeY - 14));
                break;
            case 2:
                myguienv->addImage(mydriver->getTexture("fx/Instrumentos/Fuel/fuel3.png"),position2d<int>(context.bSizeX, context.bSizeY - 14));
                break;
            case 3:
                myguienv->addImage(mydriver->getTexture("fx/Instrumentos/Fuel/fuel4.png"),position2d<int>(context.bSizeX, context.bSizeY - 14));
                break;
            case 4:
                myguienv->addImage(mydriver->getTexture("fx/Instrumentos/Fuel/fuel5.png"),position2d<int>(context.bSizeX, context.bSizeY - 14));
                break;
            case 5:
                myguienv->addImage(mydriver->getTexture("fx/Instrumentos/Fuel/fuel6.png"),position2d<int>(context.bSizeX, context.bSizeY - 14));
                break;
            case 6:
                myguienv->addImage(mydriver->getTexture("fx/Instrumentos/Fuel/fuel7.png"),position2d<int>(context.bSizeX, context.bSizeY - 14));
                return true;
                break;
            };
            if(gas == 6) gas = 0; else gas++;
    };
    return false;

};

bool Painel :: fim_de_jogo(vector3df posAviao, float veloz, bool bateu)
{
    if(inicia_jogo && !bateu)//Condição inicial;
    {
        if(posAviao.X<20.0f && posAviao.X>-20.0f && posAviao.Z<3500.0f /*&& posAviao.Y<20.0f*/)//O Avião não sai deste if enquanto não sair da pista;
            return false;
        else//Quando cair no else, quer dizer q daí sim o avião levantou voo, ou seja saiu da pista;
            inicia_jogo=false;
    };

    if(veloz<2.0f||bateu)//Quer dizer que o avião está parando;
    {
        aviso->setVisible(true);
        if(bateu)
            aviso->setMaterialTexture(0,mydriver->getTexture("fx/outros/desastre.png"));
        else
        {
            if(posAviao.X>40.0f ||posAviao.X<-40.0f || posAviao.Z<-500.0f ||posAviao.Z>3400.0f)
                aviso->setMaterialTexture(0,mydriver->getTexture("fx/outros/game_over.png"));
            else if(posAviao.X>20.0f ||posAviao.X<-20.0f)
                aviso->setMaterialTexture(0,mydriver->getTexture("fx/outros/mais_ou_menos.png"));
            else
                aviso->setMaterialTexture(0,mydriver->getTexture("fx/outros/completou.png"));
            //printf("\n%0.2f - %0.2f",posAviao.X, posAviao.Z);
        };
        if(ver1)
        {
            xIni = timer->getTime();
            ver1 = false;
            //printf("\n%d - %d Fator", xIni, timer->getSpeed());
        };
        if(xIni +6000 <timer->getTime())//Tempo que o aviso fica exibido(Tempo em Milisegundos);
            return true;

    };
    //printf("\n%0.2f",veloz);
    return false;
};

bool Painel :: mostra_warning(bool watch_out, float distancia, float altura, float raio)
{
    static bool voltar = false;///É para que quando o avião estiver saindo da rota, irá aparecer
                            ///o primeiro aviso, depois o segundo. Então se o avião voltar
                            ///para rota, não apareça novamente o primeiro aviso.
    if(watch_out || altura < -0.02f)
        return true;
    int teto=5100;
    if(distancia>23000 && distancia<27000 && !voltar)
    {
        aviso->setMaterialTexture(0,mydriver->getTexture("fx/outros/aviso1.png"));
        watch_out = true;
    }
    else if(distancia > 27000 || voltar)//27000
    {
        aviso->setMaterialTexture(0,mydriver->getTexture("fx/outros/aviso2.png"));
        watch_out = true;
        voltar = true;
    }
    else if(altura>400 && *Name == "160C")///Aviso de Altiude muito alta;
    {
        aviso->setMaterialTexture(0,mydriver->getTexture("fx/outros/aviso3.png"));
        watch_out = true;
        teto =500;
    }
    else if(altura>2000 && *Name == "thunderbolt")///Thunderbolt o limite é 2500 para explodir (9Km)
    {
        aviso->setMaterialTexture(0,mydriver->getTexture("fx/outros/aviso3.png"));
        watch_out = true;
        teto = 2500;
    }
    else if(altura>4000 && *Name == "747")///Aviso de Altiude muito alta;
    {
        aviso->setMaterialTexture(0,mydriver->getTexture("fx/outros/aviso3.png"));
        watch_out = true;
        teto = 5000;
    }
    else
        watch_out = false;

    if(voltar && distancia<23000)
        voltar = false;

    if(watch_out == true)
        aviso->setVisible(true);
    else
        aviso->setVisible(false);

    if(raio>30000 || altura> teto)
        return true;
    else
        return false;


};

void Painel :: atualizaVeloz(float atuaPont)
{
   marcVeloz->setRotation(vector3df(atuaPont + se_747_ter,0.0f,0.0f));
};

void Painel :: atualizaRPM(int atuaPont)
{
   marcRPM->setRotation(vector3df(atuaPont + ajeitaPos,0.0f,0.0f));
};

void Painel :: atualizaALT(vector3df mapeiaPos)
{   float atuaPont;
    if(*Name == "160C")
        atuaPont = mapeiaPos.Y * 0.68f;
    else if(*Name == "747")
        atuaPont = mapeiaPos.Y * 0.07f;
    else
        atuaPont = mapeiaPos.Y * 0.135f;

   marcALT->setRotation(vector3df(15.0f + atuaPont,0.0f,0.0f));
   ///************MAPA***********************************
   if(mapeiaPos.X>-1000.0f &&mapeiaPos.X< 1000.0f && mapeiaPos.Z> -30.0f && mapeiaPos.Z < 15000.0f)
   {
       if(mapeiaPos.X<10.0f && mapeiaPos.X>-10.0f)
            mapa_1->setMaterialTexture(0,mydriver->getTexture("fx/Instrumentos/Bussula/mapa_alinhado.jpg"));
        else if(mapeiaPos.X>10.0f && mapeiaPos.X<50.0f)
            mapa_1->setMaterialTexture(0,mydriver->getTexture("fx/Instrumentos/Bussula/mp_sul.jpg"));
        else if(mapeiaPos.X<-10.0f && mapeiaPos.X>-50.0f)
            mapa_1->setMaterialTexture(0,mydriver->getTexture("fx/Instrumentos/Bussula/mp_norte.jpg"));
        else
            mapa_1->setMaterialTexture(0,mydriver->getTexture("fx/Instrumentos/Bussula/mapa_pouso.jpg"));
        //localizar->setScale(vector3df(1.0f, 2.0f, 1.0f));
        localizar->setPosition(vector3df(0.005f, 1.1f - mapeiaPos.X/10000, -1.4f + mapeiaPos.Z/25000));
   }
    else
    {
        localizar->setScale(vector3df(1.0f));
        mapa_1->setMaterialTexture(0,mydriver->getTexture("fx/Instrumentos/Bussula/Mapa.jpg"));
        localizar->setPosition(vector3df(0.005f, 1.1f - mapeiaPos.X/100000, -1.4f + mapeiaPos.Z/100000));
    };

    //localizar->setMaterialTexture(0,mydriver->getTexture("fx/Instrumentos/Bussula/pontinho.jpg"));
};

//void Painel :: rotBussula(f32 orient)
void Painel :: rotBussula(vector3df orient)
{
    bussula->setRotation(vector3df(-1.0f * orient.Y + 90.0f ,0.0f, 0.0f));
};
//vector3df -> gethorizontal angulos

///CLASSE INCENDIO

incendio::incendio(IrrlichtDevice * device, vector3df posicao, int tipo)
{
    ISceneManager * smgr = device->getSceneManager();
    IVideoDriver * driver = device->getVideoDriver();

    denso = driver->getTexture("media/denso.png");
    normal = driver->getTexture("media/normal.png");
    fraco = driver->getTexture("media/fraco.png");
    ativo = false;
    tempo = 0;
    start = 0;
    expAni = 0;
    tipoExp = tipo;

    for (int i = 0; i < 20; i++)
    {
        fumaca[i].fumaca = smgr->addBillboardSceneNode(0,dimension2d<f32>(7.0f, 7.0f), posicao);
        fumaca[i].fumaca -> setMaterialType(EMT_TRANSPARENT_ALPHA_CHANNEL);
        fumaca[i].fumaca -> setVisible(false);
        fumaca[i].fumaca -> setMaterialTexture(0,denso);
        fumaca[i].posicao = posicao;
        fumaca[i].ativo = false;
        fumaca[i].tempo = 0;
    };

    explosao = smgr->addBillboardSceneNode(0,dimension2d<f32>(35.0f, 75.0f), vector3df(posicao.X, posicao.Y + 23, posicao.Z));
    explosao -> setMaterialFlag(EMF_LIGHTING, false);
    explosao -> setMaterialType(EMT_TRANSPARENT_ALPHA_CHANNEL);
    explosao -> setVisible(false);

    //carregar sprites da explosão
    stringw expString;
    for (int i = 0; i < 14; i++)
    {
        switch (tipoExp)
        {
            case 0: //fogo
                expString = ((stringw)L"fx/explosao/exp0" + (stringw)(i+1) + L".png");
                expSprite.push_back(driver->getTexture(expString));
                break;

            case 1: //agua
                expString = ((stringw)L"fx/explosao/exp0" + (stringw)(i+1) + L".png");
                expSprite.push_back(driver->getTexture(expString));
                break;

        };
    };
};

void incendio::animar()
{
  // if (!ativo)
    //    return;

    tempo++;

    if(start == 0) //so acontece uma vez
        explosao->setVisible(true);

    if(expAni < expSprite.size()-1)
    {
        if (tempo%4 == 0)
            expAni ++;
        explosao -> setMaterialTexture(0,expSprite[expAni]);
        //printf("\nExp %d - temp %d",expAni, tempo);
    }
    else
        explosao->setVisible(false);
    //rotina de fumaça
    if (tipoExp == 1) //se for agua, sem fumaca
        return;

    if (start < 19)
    {
        if(tempo > 30)
        {
            start ++;
            tempo = 0;
            fumaca[start].ativo = true;
            fumaca[start].fumaca -> setVisible(true);
        };
    };

    for (int i = 0; i < 20; i ++)
    {
        if(fumaca[i].ativo)
        {
            fumaca[i].tempo ++;
            fumaca[i].fumaca -> setPosition(vector3df(fumaca[i].posicao.X,
                                                      fumaca[i].posicao.Y + fumaca[i].tempo/20,
                                                      fumaca[i].posicao.Z));// + fumaca[i].tempo/40));
            float scale = 3.0f + fumaca[i].tempo / 50;
            fumaca[i].fumaca->setSize(dimension2d<f32>(scale * 1.5, scale * 1.5));

            if(fumaca[i].tempo == 1)
                fumaca[i].fumaca -> setMaterialTexture(0,denso);
            else if (fumaca[i].tempo == 20)
                fumaca[i].fumaca -> setMaterialTexture(0,normal);
            else if (fumaca[i].tempo == 130)
                fumaca[i].fumaca -> setMaterialTexture(0,fraco);
            else if (fumaca[i].tempo >= 300)
            {
                fumaca[i].tempo = 0;
                if (apagar)
                    fumaca[i].fumaca -> setVisible(false);
            }
       };
    };
};

void incendio::apagarInc()
{
    apagar = true;
}

int incendio::getFrame()
{
    return expAni;
}

void incendio::setExplosaoEm(vector3df posicao)
{
    explosao -> setVisible(true);
    explosao -> setPosition(posicao);
    start = 0;
    expAni = 0;
    tempo = 0;
    ativo = true;
    explosao -> setMaterialTexture(0,expSprite[expAni]);

    for (int i = 0; i < 20; i++)
        fumaca[i].fumaca -> setPosition(posicao);
};

void incendio ::atualizaPosition(vector3df posicao)
{
    static bool test = true;
    explosao -> setPosition(posicao);
};






