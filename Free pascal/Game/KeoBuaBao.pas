Program Keo_Bua_Bao;
uses crt;
var player,bot:string;
    scorePlr,scoreBot,scoreDraw:byte;

procedure Input(var player:string);
begin
  writeln('Player: ',scorePlr,' Draw: ',scoreDraw,' Bot: ',scoreBot);
  write('Enter Keo or Bua or Bao: ');readln(player);
  while ((player<>'Keo') and (player<>'Bua') and (player<>'Bao')) do
    begin
      write('Please enter Keo or Bua or Bao: ');readln(player);
    end;
end;

procedure Computer(var bot:string);
var t:byte;
begin
  randomize;
  t:=random(3);
  if (t=0) then
    bot:='Keo'
  else
    if (t=1) then
      bot:='Bua'
    else
      if (t=2) then
        bot:='Bao';
end;

function Wins(player,bot:string):byte;
begin
  if (player=bot) then
    exit(1);
  if (player='Keo') then
    begin
      if (bot='Bua') then
        exit(3);
      exit(2);
    end;
  if (player='Bua') then
    begin
      if (bot='Bao') then
        exit(3);
      exit(2);
    end;
  if (player='Bao') then
    begin
      if (bot='Keo') then
        exit(3);
      exit(2);
    end;  
end;

procedure Run();
var ch:char;
begin
  scorePlr:=0;
  scoreBot:=0;
  scoreDraw:=0;
  repeat
    clrscr;
    Input(player);
    Computer(bot);
    writeln('You choice: ',player);
    writeln('Computer choise: ',bot);
    if (Wins(player,bot)=1) then
      begin 
        writeln('Draw');
        inc(scoreDraw);
      end
    else
      if (Wins(player,bot)=2) then
        begin
          writeln('You Wins');
          inc(scorePlr);
        end
      else
        if (Wins(player,bot)=3) then
          begin
            writeln('You Lose');
            inc(scoreBot);
          end;
    writeln('Enter Y to play a new game');
    writeln('Enter N to exit the game');
    writeln('--------------------------');
    write('Your choice is: ');readln(ch);
  until ((ch='N') or (ch='n')); 
end;

Begin
  clrscr;
  Run();
  readln  
End.