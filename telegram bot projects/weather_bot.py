from aiogram import Bot,Dispatcher,executor,types
import requests as rq 
from bs4 import BeautifulSoup as bs

Token = '7076471813:AAFVjbV8HoPUgEA8WtN3goOsvVHUa5zok4Q'
bot = Bot(token=Token)
dp = Dispatcher(bot)

m = """
🔥به بات هواشناسی خوش آمدید🔥

برای شروع فقط کافیه اسم یه شهر برام بفرستی...😍
"""

@dp.message_handler(commands=['start','help'])
async def first(pm: types.Message):
    await pm.reply(m)

@dp.message_handler()
async def hava(pm: types.Message):
    loc = str(pm.text)
    url = f"https://www.google.com/search?q=weather+{loc.replace(' ','')}"
    session = rq.Session()
    session.headers['User-Agent'] = "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/94.0.4606.81 Safari/537.36"
    html = session.get(url)
    soup = bs(html.text,"html.parser")

    city = soup.find('span',attrs={'class':'BBwThe'}).text
    time = soup.find('div',attrs={'class':'wob_dts'}).text
    weather = soup.find('span',attrs={'id':'wob_dc'}).text
    temp = soup.find('span',attrs={'id':'wob_tm'}).text

    await pm.answer(f"City {city} in {time}")
    await pm.answer(f"Weather:{weather} and temp:{temp}°C")

if __name__ == "__main__":
    executor.start_polling(dp,skip_updates=True)