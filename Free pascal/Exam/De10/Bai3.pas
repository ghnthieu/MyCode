Program ssnt;
uses crt;
var n:byte;
procedure nhap(var n:byte);
begin
  write('Nhap so N: ');readln(n);
end;
function snt(n:longint):boolean;
var i:longint;
begin
  if n<2 then
    exit(false)
  else
    for i:=2 to trunc(sqrt(n)) do
      if n mod i=0 then
        exit(false);
  exit(true);
end;
procedure xuly(n:byte);
var i,j,k,ka,kb:byte;
    a,b:array[1..100] of longint;
begin
  ka:=1;
  a[ka]:=0;
  for i:=1 to n do
    begin
      kb:=0;
      for k:=1 to ka do
        for j:=0 to 9 do
          if snt(a[k]*10+j) then
            begin
              inc(kb);
              b[kb]:=a[k]*10+j;
            end;
      ka:=kb;
      for k:=1 to ka do
        a[k]:=b[k];
    end;
  write('Cac so sieu nguyen to co ',n,' chu so la: ');
  for i:=1 to ka do
    write(a[i],' ');
  writeln;
  write('Tat ca co ',ka,' so sieu nguyen to');
end;
Begin
  clrscr;
  nhap(n);
  xuly(n);
  readln
End.
