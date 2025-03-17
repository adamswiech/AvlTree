using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace projekt_Kamil.Modules
{
    internal class ClassicThrow
    {

        Random random = new Random();
        private int damage = 0;
        private int hit = 0;
        private int critHit = 0;
        private int wound = 0;
        public ClassicThrow()
        {

        }

        public string Calkulate(int quantity, int bs , bool relOnes,int S, int T, int AP, int Sv)
        {
            float hitS = 0;
            float critS = 0;
            float woundS = 0;
            float wooundS = 0;
            float damageS = 0;
            for (int i = 0; i < 100000; i++)
            {
                HitThrow(quantity, bs, relOnes);
                WoundThrow(S, T);
                ArrmorSave(Sv, AP);
                //damage += critHit;
                hitS += hit;
                critS += critHit;
                woundS += wound;
                damageS += damage;
                hit = 0;
                critHit = 0;
                wound = 0;
                damage = 0;
            }
            hitS /= 100000;
            critS /= 100000;
            woundS /= 100000;
            damageS /= 100000;
            return $"hits : {hitS} \ncrit hits : {critS}\nwounds ; {woundS}\ndamage : {damageS}";
            //return $"hits : {hit} \ncrit hits : {critHit}\nwounds ; {wound}\ndamage : {damage}";
        }

        public void HitThrow(int quantity, int bs,bool relOnes)
        {
            int tmpRandom;
            for (int i = 0; i < quantity; i++)
            {
                tmpRandom = random.Next(1, 7);

                if (tmpRandom == 1 && relOnes)
                    tmpRandom = random.Next(1, 6);

                if (tmpRandom >= bs)
                {
                    
                    if (tmpRandom == 6)
                        critHit++;
                    else
                        hit++;
                }
            }
            
        }

        private void WoundThrow(float s, float t)
        {
            for (int i = 0; i < hit; i++)
            {
                if (s >= t * 2)
                {
                    if (random.Next(1, 7) >= 2)
                        wound++;
                    continue;
                }

                if (s > t)
                {
                    if (random.Next(1, 7) >= 3)
                        wound++;
                    continue;
                }

                if (s == t)
                {
                    if (random.Next(1, 7) >= 4)
                        wound++;
                    continue;
                }

                if (s * 2 <= t)
                {
                    if (random.Next(1, 7) == 6)
                        wound++;
                    continue;
                }

                if (s < t)
                {
                    if (random.Next(1, 6) >= 5)
                        wound++;
                    continue;
                }

            }
        }

        private void ArrmorSave(int sv , int ap)
        {
            sv +=ap;
            if(sv<2)
                sv = 2;
            if (sv > 6)
                sv = 6;
            for (int i = 0; i < wound; i++)
            {
                if (random.Next(1, 7) < sv)
                    damage++;
            }
        }

        private void InvurnabilitySave()
        {
            for (int i = 0; i < wound; i++)
            {
                if (random.Next(1, 7) != 6)
                    damage++;
            }
        }
    }
}
