import { expect, test } from '@playwright/test';

test.describe('карта на факултетите', () => {
    test.beforeEach(async ({ page }) => {
        // Не искаме всеки тест да извиква OpenStreetMap, затова връщаме празни отговори
        // на всички завки към OpenStreetMap
        await page.route('https://tile.openstreetmap.org/**', async (route) => {
            await route.fulfill();
        });
    });

    test('списък с факултелтетите', async ({ page }) => {
        await page.goto('/');

        await page.getByRole('combobox', { name: 'Изберете факултет' }).click();
        const facultyOptions = page.getByRole('option');

        await expect(facultyOptions).toHaveText(NAMES);
        await expect(page).toHaveScreenshot();
    });

    test('избор на факултет', async ({ page }) => {
        await page.goto('/');

        for (const faculty of FACULTIES) {
            await page.getByRole('combobox', { name: 'Изберете факултет' }).click();
            await page.getByRole('option', { name: faculty.name}).click();

            await expect(page.getByRole('paragraph')).toContainText(faculty.address);
        }

        await expect(page).toHaveScreenshot();
    });
});

const FACULTIES = [
    {
        name: 'Стопански факултет',
        address: 'София 1113, бул. Цариградско шосе 125',
    },
    {
        name: 'Исторически факултет',
        address: 'София 1504, бул. Цар Освободител 15',
    },
    {
        name: 'Факултет по математика и информатика',
        address: 'София 1164, бул. Джеймс Баучър 5',
    },
];
const NAMES = FACULTIES.map(f => f.name);
