from aiogram import Dispatcher, executor, Bot, types
import pyqrcode

Token = '7076471813:AAFVjbV8HoPUgEA8WtN3goOsvVHUa5zok4Q'

bot = Bot(Token)
dp =  Dispatcher(bot)

@dp.message_handler(commands=["start", "help"])
async def start(pm: types.Message):
    await pm.answer("give a sentence and ill give u qrcode ")

@dp.message_handler()
async def QRcode(pm: types.Message):
    txt = str(pm.text)
    qr = pyqrcode.create(txt)
    qr.png("QRdcode.png", scale=5)

    await bot.send_photo(
        chat_id=pm.from_user.id,
        photo = open("qrcode.png", "rb"),
        caption= f"<tg-spoiler>{pm.text}</tg-spoiler>",
        parse_mode="HTML"
    )
    
    

if __name__ == "__main__":
    executor.start_polling(dp, skip_updates=True,on_startup=start)
