const int NumChannels = 12;
bool OutState;

void setup()
{
  OutState = false;

  for(int i = 2; i < NumChannels + 2; ++i)
  {
    pinMode(i, OUTPUT);
  }
}


void loop()
{
  ToneGen(30000);
}

void ToneGen(int Freq_Hz)
{
  int Period_Partial = (int)(((double)NumChannels / (double)Freq_Hz) * 1000000.0); // 1 / Hz = period in seconds

  while(true)
  {
    OutState = !OutState;

    for(int i = 2; i < NumChannels + 2; ++i)
    {
      delayMicroseconds(Period_Partial);
      digitalWrite(i, OutState);
    }
  }
}











