Program bai1;
uses crt;
type mang=array[1..100] of qword;
var n:byte;
    f:mang;
procedure nhap(var n:byte);
begin
  repeat
    readln(n);
  until (n>=1) and (n<=100);
end;
procedure khoitao(var f:mang);
var i:byte;
begin
  F[1]:=1;
  F[2]:=1;
  for i:=3 to 93 do
    F[i]:=F[i-1]+F[i-2];
end;
procedure xuly(n:byte; f:mang);
var i:byte;
begin
  for i:=1 to 93 do
    begin
      if f[i]=n then
        begin
          write('Yes');
          break;
        end;
      if f[i]>n then
        begin
          write('No');
          break;
        end;
    end;
end;
Begin
  clrscr;
  nhap(n);
  khoitao(f);
  xuly(n,f);
  readln
End.
