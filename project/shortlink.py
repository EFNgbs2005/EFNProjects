from aiogram import Bot, executor, Dispatcher, types
import pyshorteners
import time

API_TOKEN = '7076471813:AAFVjbV8HoPUgEA8WtN3goOsvVHUa5zok4Q'

bot = Bot(token=API_TOKEN)
dp = Dispatcher(bot)
sl = pyshorteners.Shortener()

async def start(_):
    print("Bot started!")
    print(time.time())

async def down(_):
    print("Bot shutdown!")
    print(time.time())

@dp.message_handler(commands='start')
async def start(pm: types.Message):
    await pm.reply("hello welcome to this bot")


@dp.message_handler(commands='help')
async def help(pm: types.Message):
    await pm.reply("""this is test bot :)
this bot can make short link for u if u want it : @short  << your link >>""")


@dp.message_handler()
async def shortlink(pm: types.Message):
    if pm.text[0:7] == "@short " :
        await pm.answer("Wait second!!!")
        link = str(pm.text[7:])
        short_link = sl.osdb.short(link)
        await pm.answer(short_link)
    else:
        await pm.answer("use this format: @short << your link >>")

if __name__ == "__main__":
    executor.start_polling(dp,skip_updates=True, on_startup=start, on_shutdown=down)