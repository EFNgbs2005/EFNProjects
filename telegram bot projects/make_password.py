import random
import string
from aiogram import Bot, Dispatcher, types
from aiogram.contrib.fsm_storage.memory import MemoryStorage
from aiogram.dispatcher import FSMContext
from aiogram.dispatcher import filters
from aiogram.utils import executor

API_TOKEN = '7076471813:AAFVjbV8HoPUgEA8WtN3goOsvVHUa5zok4Q'

bot = Bot(token=API_TOKEN)
storage = MemoryStorage()
dp = Dispatcher(bot, storage=storage)

@dp.message_handler(commands=['start'])
async def cmd_start(message: types.Message):
    await message.answer("سلام! لطفاً یک عدد وارد کنید تا رمز به طول آن تولید شود.")

@dp.message_handler(lambda message: message.text.isdigit())
async def generate_password(message: types.Message):
    length = int(message.text)
    if length <= 0:
        await message.answer("لطفاً یک عدد مثبت وارد کنید.")
        return
    
    characters = string.digits
    password = ''.join(random.choice(characters) for _ in range(length))
    
    await message.answer(f"رمز تولید شده: {password}")

@dp.message_handler()
async def handle_invalid_input(message: types.Message):
    await message.answer("لطفاً یک عدد صحیح وارد کنید.")

if __name__ == '__main__':
    executor.start_polling(dp, skip_updates=True)
