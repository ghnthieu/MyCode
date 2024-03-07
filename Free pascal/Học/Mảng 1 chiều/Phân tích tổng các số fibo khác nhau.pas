Program Pt_fibo;
type mangf=array[1..44] of longint;
     mangt=array[1..44] of int64;
var fibo:mangf;
    s:mangt;
const fi='BAI2.INP';
      fo='BAI2.OUT';
procedure khoitao(var fibo:mangf; var s:mangt);
var i:byte;
begin
  fibo[1]:=1;
  fibo[2]:=2;
  for i:=3 to 44 do
    fibo[i]:=fibo[i-1]+fibo[i-2];
  s[1]:=fibo[1];
  for i:=2 to 44 do
    s[i]:=s[i-1]+fibo[i];
end;
function kt(n:longint):boolean;
var i:byte;
begin
  for i:=1 to 44 do
    if (n=fibo[i]) then
      exit(true);
  exit(false);
end;
procedure xuly;
var f1,f2:text;
    i,j:byte;
    t:longint;
    n:integer;
begin
  assign(f1,fi);reset(f1);
  assign(f2,fo);rewrite(f2);
  while (not eof(f1)) do
    begin
      readln(f1,n);
      khoitao(fibo,s);
      for i:=1 to 44 do
        if (s[i]>n) then
          break;
      t:=s[i]-n;
      if (kt(t)) then
        begin
          for j:=i downto 1 do
            if (fibo[j]=t) then
              fibo[j]:=0;
          for j:=1 to i do
            if (fibo[j]>0) then
              write(f2,fibo[j],' ');
          writeln(f2);
        end
      else
        begin
          j:=i;
          while (j>=1) do
            begin
              if (t-fibo[j]>=0) then
                begin
                  dec(t,fibo[j]);
                  fibo[j]:=0;
                end;
              if (t=0) then
                break;
              dec(j);
            end;
          for j:=1 to i do
            if (fibo[j]>0) then
              write(f2,fibo[j],' ');
          writeln(f2);
        end;
    end;
  close(f1);
  close(f2);
end;
Begin
  xuly;
End.


