
int main()
{
  string cmd;
  while(getline(cin,cmd)){
    size_t last_index = cmd.find_last_not_of("0123456789");
    string numstr = cmd.substr(last_index + 1);
    int num = stoi(numstr);
    if(cmd.substr(0,10) == "InsertBack"){

    }
    else if(cmd.substr(0,11) == "InsertAfter"){

    }
    else if(cmd.substr(0,9) == "DeleteAll"){

    }
    else if(cmd.substr(0,6) == "Delete"){

    }
  }
  return 0;
}
