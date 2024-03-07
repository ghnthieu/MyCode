Program day_fibonacci;
uses crt;
type mang=array[1..100] of qword;
var n:longint;
    F:mang;
procedure nhap(var n:longint);
begin
  repeat
    write('nhap so nguyen duong N: ');readln(n);
  until (n>=1) and (n<=1000000000);
end;
procedure khoi_tao(var F:mang; n:longint);
var i:byte;
begin
  F[1]:=1;
  F[2]:=1;
  for i:=3 to 93 do
    begin
      F[i]:=F[i-1]+F[i-2];
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
  khoi_Tao(F,n);
  readln
End.
