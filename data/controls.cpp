#include "controls.h"

void readControls(MyEventReceiver * receiver, SEngineFighter * player, ISoundEngine * sEngine, controles botJoy, sons *audio)
{
    SEvent::SJoystickEvent joystickData = receiver->GetJoystickState();
    //FLAPE (SOBE E DESCE)
    static u16 flapOn = 0;

    if (receiver->IsKeyDown(KEY_KEY_F)||joystickData.IsButtonPressed(botJoy.triangulo))//Triangulo
        flapOn = 1;
    else
        flapOn = 0;

    for (u16 i = 0; i < player->getCommandArray()[FLAP].size(); i++)
            player->setCommand(player->getCommandArray()[FLAP][i],flapOn,FLAP);

    //EJETAR (ABRIR A CARLINGA)
    static u16 ejectOn = 0;

    if (receiver->IsKeyDown(KEY_KEY_T) ||joystickData.IsButtonPressed(botJoy.digEsq))//Aperte Digital esquerdo
        ejectOn = 1;
    else
        ejectOn = 0;

    for (u16 i = 0; i < player->getCommandArray()[EJECT].size(); i++)
            player->setCommand(player->getCommandArray()[EJECT][i],ejectOn,EJECT);

    //OPERAR TRENS DE ATERRISSAGEM

    if (receiver->IsKeyDown(KEY_KEY_G)||joystickData.IsButtonPressed(botJoy.circulo))//Circulo
        botJoy.gearOn = 1;
    else
        botJoy.gearOn = 0;

    for (u16 i = 0; i < player->getCommandArray()[GEAR].size(); i++)
        player->setCommand(player->getCommandArray()[GEAR][i],botJoy.gearOn,GEAR);

    player->checkLanding();

    //AILERONS
    if (receiver->IsKeyDown(KEY_KEY_A)||joystickData.POV/100>180 && joystickData.POV/100<300 && botJoy.ajeitaDir==true
        ||((f32)joystickData.Axis[SEvent::SJoystickEvent::AXIS_X]/32767.f) <= -1)
    {
        for (u16 i = 0; i < player->getCommandArray()[ROLL].size(); i++)
            player->setCommand(player->getCommandArray()[ROLL][i],1,ROLL);
    }
    else if (receiver->IsKeyDown(KEY_KEY_D)||joystickData.POV/100>70 && joystickData.POV/100<180 && botJoy.ajeitaDir==true
             ||((f32)joystickData.Axis[SEvent::SJoystickEvent::AXIS_X]/32767.f) >= 1)
    {
        for (u16 i = 0; i < player->getCommandArray()[ROLL].size(); i++)
            player->setCommand(player->getCommandArray()[ROLL][i],2,ROLL);
    }
    else
    {
        for (u16 i = 0; i < player->getCommandArray()[ROLL].size(); i++)
            player->setCommand(player->getCommandArray()[ROLL][i],0,ROLL);
    };
    //printf("\n%d",joystickData.POV/100);
    //PROFUNDORES
    if (receiver->IsKeyDown(KEY_KEY_W)||joystickData.POV/100 == 0 && botJoy.ajeitaDir==true
        ||((f32)joystickData.Axis[SEvent::SJoystickEvent::AXIS_Y]/32767.f) <= -1)
    {
        for (u16 i = 0; i < player->getCommandArray()[PITCH].size(); i++)
            player->setCommand(player->getCommandArray()[PITCH][i],1,PITCH);
    }
    else if (receiver->IsKeyDown(KEY_KEY_S)|| joystickData.POV/100>160 && joystickData.POV/100<230 && botJoy.ajeitaDir==true
             ||((f32)joystickData.Axis[SEvent::SJoystickEvent::AXIS_Y]/32767.f) >= 1)
    {
        for (u16 i = 0; i < player->getCommandArray()[PITCH].size(); i++)
            player->setCommand(player->getCommandArray()[PITCH][i],2,PITCH);
    }
    else
    {
        for (u16 i = 0; i < player->getCommandArray()[PITCH].size(); i++)
            player->setCommand(player->getCommandArray()[PITCH][i],0,PITCH);
    };
    //printf("\n%0.2f",joystickData.Axis[SEvent::SJoystickEvent::AXIS_Y]/32767.f);
    //printf("\n\n%d",botJoy.ajeitaDir);
    //system("pause");
    //LEME VERTICAL
    if (receiver->IsKeyDown(KEY_KEY_Q)||joystickData.IsButtonPressed(botJoy.r1))//R1
    {
        for (u16 i = 0; i < player->getCommandArray()[YAW].size(); i++)
            player->setCommand(player->getCommandArray()[YAW][i],1,YAW);
    }
    else if (receiver->IsKeyDown(KEY_KEY_E)||joystickData.IsButtonPressed(botJoy.l1))//L1
    {
        for (u16 i = 0; i < player->getCommandArray()[YAW].size(); i++)
            player->setCommand(player->getCommandArray()[YAW][i],2,YAW);
    }
    else
    {
        for (u16 i = 0; i < player->getCommandArray()[YAW].size(); i++)
            player->setCommand(player->getCommandArray()[YAW][i],0,YAW);
    };

    u16 acc;

    //PARTIDA NO MOTOR
    static bool engineOn = true;

   if (receiver->IsKeyDown(KEY_KEY_M)||joystickData.IsButtonPressed(botJoy.l2))//L2
    {
        if(engineOn)
        {
            if(!audio->musicLiga)
            {
                audio->startMotor(sEngine);
                audio->musicLiga = true;
                audio->musicSet = false;
            };
            if (!player->getEngineState())
            {
                player->startEngine(true);
                acc=2;
            }
            else
            {
                sEngine->removeSoundSource(audio->somPlane);//Remove o som da memória
                sEngine->play2D(audio->somPlane,true,true,true,true);
                audio->musicLiga = false;
                player->startEngine(false);
            };
            engineOn = false;
        }
    }
    else
        engineOn = true;

    //ACELERAÇÃO DO MOTOR
    bool acelerando =false;
    if (receiver->IsKeyDown(KEY_UP)||joystickData.IsButtonPressed(botJoy.xX))//X
    {
        //static float musicAccel = 0.2f;
            if(!audio->musicSet && player->motorLig)
            {
                audio->somPlane->setDefaultVolume(0.4f);
                sEngine->play2D(audio->somPlane,true,false,true,true);
                audio->musicSet= true;
            };
        acc = 2;
        acelerando = true;
    }
    else if (receiver->IsKeyDown(KEY_DOWN)||joystickData.IsButtonPressed(botJoy.quadrado))//Quadrado
        acc = 0;
    else
        acc = 1;

    player->accelerate(acc, acelerando);
    //ATIRAR
    if(!player->isCivilian())//se não for avião civil
    {
        if (receiver->IsKeyDown(KEY_SPACE)/*||joystickData.AXIS_X / 32767.f*/)
            player->setShot(true);
        else
            player->setShot(false);
        //printf("\n%d",joystickData.AXIS_X /32767.f);
        static u16 selGun = 0;
        player->getGunArray()[selGun]->evaluate();
        selGun ++;
        if (selGun >= player->getGunArray().size())
            selGun = 0;
    };
};

sons :: sons(ISoundEngine * sEngine, stringw aviao)
{
    musicLiga =false;//Para evitar ecos na inicialização do som do avião
    musicSet =false;
    musicExpl = false;
    namePlane = aviao;
    sEngine->setSoundVolume(1.0f);
    musicaFundo = sEngine->addSoundSourceFromFile("musica/fundo.wav");
    musicaFundo-> setDefaultVolume(0.4);
    sEngine->play2D(musicaFundo,true,false,false,true);

    explodir =sEngine->addSoundSourceFromFile("musica/bomba.wav");
    explodir->setDefaultVolume(1.0);

    if(namePlane == "747")
    {
        somPlane = sEngine->addSoundSourceFromFile("musica/747_ENG.wav");
        ligEngine = sEngine->addSoundSourceFromFile("musica/747_ligando.wav");
    }
    else if(namePlane == "thunderbolt")
    {
        somPlane = sEngine->addSoundSourceFromFile("musica/p47_ENG.wav");
    }
    else
    {
        somPlane = sEngine->addSoundSourceFromFile("musica/160C_Eng.wav");
        ligEngine = sEngine->addSoundSourceFromFile("musica/160C_liga.wav");
    };

};
void sons :: startMotor(ISoundEngine * sEngine)
{
    if(namePlane == "thunderbolt")
    {
        somPlane->setDefaultVolume(0.2f);
        sEngine->play2D("musica/p47_liga.wav",false);
        sEngine->play2D(somPlane,true, false, true,true);
    }
    else if(namePlane == "747")
    {
        somPlane->setDefaultVolume(0.2f);
        ligEngine->setDefaultVolume(0.3f);
        sEngine->play2D(ligEngine,false,false,false);
        sEngine->play2D(somPlane,true, false, true,true);
    }
    else
    {
        somPlane->setDefaultVolume(0.3f);
        ligEngine->setDefaultVolume(0.5f);
        sEngine->play2D(ligEngine,false,false,false);
        sEngine->play2D(somPlane,true, false, true,true);
    };
};
