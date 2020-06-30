#pragma once

void Redirected_Chat_Print_Formatted(void* Chat, void* Unknown_Parameter_1, void* Unknown_Parameter_2, char* Message, ...)
{
	va_list Variadic_Parameters;

	va_start(Variadic_Parameters, Message);

	char Formatted_Message[4096];

	vsnprintf(Formatted_Message, sizeof Formatted_Message, Message, Variadic_Parameters);

	va_end(Variadic_Parameters);

	if (strlen(Formatted_Message) == 12)
	{
		__int8 Handle_Formatted_Message_Return_Value;

		auto Handle_Formatted_Message = [&]() -> __int8
		{
			if (strncmp(Formatted_Message, "[ Magic ] A", 11) == 0)
			{
				Menu_Select::Freeze_Controlled_Creature = 2;

				Recorder_User_Comamand_Number_History.push_back(Copy_User_Command::Recorder_User_Comamand_Number);

				Recorder_User_Comamand_Number_History_Number = Recorder_User_Comamand_Number_Greatest_History_Number;

				Recorder_User_Comamand_Number_Greatest_History_Number += 1;

				return 1;
			}
			else
			{
				if (strncmp(Formatted_Message, "[ Magic ] B", 11) == 0)
				{
					Recorder_User_Comamand_Number_History_Number -= 1;

					return 1;
				}
				else
				{
					if (strncmp(Formatted_Message, "[ Magic ] C", 11) == 0)
					{
						Recorder_User_Comamand_Number_History_Number += 1;

						return 1;
					}
					else
					{
						if (strncmp(Formatted_Message, "[ Magic ] D", 11) == 0)
						{
							Menu_Select::Freeze_Controlled_Creature = 2;

							unsigned __int32 Future_Recorder_User_Comamand_Number = Recorder_User_Comamand_Number_History.at(Recorder_User_Comamand_Number_History_Number);

							if (Menu_Select::User_Commands_Recorder_Record == 1)
							{
								Copy_User_Command::Recorded_User_Commands.resize(Future_Recorder_User_Comamand_Number);
							}

							Copy_User_Command::Recorder_User_Comamand_Number = Future_Recorder_User_Comamand_Number;

							return 1;
						}

						return 0;
					}
				}
			}
		};

		if (Menu_Select::User_Commands_Recorder_Record == 1)
		{
			Handle_Formatted_Message_Return_Value = Handle_Formatted_Message();
		}
		else
		{
			if (Menu_Select::User_Commands_Recorder_Playback == 1)
			{
				Handle_Formatted_Message_Return_Value = Handle_Formatted_Message();
			}
			else
			{
				Handle_Formatted_Message_Return_Value = 0;
			}
		}

		if (Handle_Formatted_Message_Return_Value == 0)
		{
			if (strncmp(Formatted_Message, "[ Magic ] E", 11) == 0)
			{
				if (Menu_Select::User_Commands_Recorder_Record == 1)
				{
					Copy_User_Command::Recorded_User_Commands.clear();

					Copy_User_Command::Recorder_User_Comamand_Number = 0;
				}

				Recorder_User_Comamand_Number_History.clear();

				Recorder_User_Comamand_Number_History_Number = 0;

				Recorder_User_Comamand_Number_Greatest_History_Number = 0;
			}
		}
	}

	using Chat_Print_Formatted_Type = void(__cdecl*)(void* Chat, void* Unknown_Parameter_1, void* Unknown_Parameter_2, char* Message);

	Chat_Print_Formatted_Type((unsigned __int32)Original_Chat_Print_Formatted_Caller_Location)(Chat, Unknown_Parameter_1, Unknown_Parameter_2, Formatted_Message);
}