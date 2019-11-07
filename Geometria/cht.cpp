//calcular valor para posicion d para la linea que inicia en pa.s.s con pendiente pa.d y con adicion de pa.s.f
ll cal(pair<ll, pair<ll, ll>> pa, ll d)
{
	return pa.s.f + (d - pa.s.s) * pa.f;
}
//calcula la interseccion
ld supe(pair<ll, pair<ll, ll>> pa, pair<ll, pair<ll, ll>> pe)
{
	pe.s.f -= pe.f * pe.s.s;
	pa.s.f -= pa.f * pa.s.s;
	return ((ld)pe.s.f - pa.s.f) / ((ld)pa.f - pe.f);
}
